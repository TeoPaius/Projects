using System;
using System.Collections.Generic;
using System.Text;

namespace ChatServer
{
    //--------------------
    // Packet Structure
    //--------------------

    // Description   -> |dataIdentifier|name length|message length|    name   |    message   |
    // Size in bytes -> |       4      |     4     |       4      |name length|message length|

    public enum DataIdentifier
    {
        Message,
        LogIn,
        LogOut,
        Null,
        FLogIn,
        SignUp,
        FSignUp,
        Online
    }

    public class Packet
    {
        #region Private Members
        private DataIdentifier dataIdentifier;
        private string name;
        private string message;
        #endregion

        #region Public Properties
        public DataIdentifier ChatDataIdentifier
        {
            get { return dataIdentifier; }
            set { dataIdentifier = value; }
        }

        public string ChatName
        {
            get { return name; }
            set { name = value; }
        }

        public string ChatMessage
        {
            get { return message; }
            set { message = value; }
        }
        #endregion

        #region Methods

        public Packet()
        {
            dataIdentifier = DataIdentifier.Null;
            message = null;
            name = null;
        }

        public Packet(byte[] dataStream)
        {
            dataIdentifier = (DataIdentifier)BitConverter.ToInt32(dataStream, 0);
            int nameLength = BitConverter.ToInt32(dataStream, 4);
            int msgLength = BitConverter.ToInt32(dataStream, 8);

            if (nameLength > 0)
                name = Encoding.ASCII.GetString(dataStream, 12, nameLength);
            else
                name = null;

            if (msgLength > 0)
                message = Encoding.ASCII.GetString(dataStream, 12 + name.Length, msgLength);
            else
                message = null;
        }

        public byte[] GetDataStream()
        {
            List<byte> packetDataStream = new List<byte>();

            packetDataStream.AddRange(BitConverter.GetBytes((int)dataIdentifier));

            if (name != null)
                packetDataStream.AddRange(BitConverter.GetBytes(name.Length));
            else
                packetDataStream.AddRange(BitConverter.GetBytes(0));

            if (message != null)
                packetDataStream.AddRange(BitConverter.GetBytes(message.Length));
            else
                packetDataStream.AddRange(BitConverter.GetBytes(0));

            if (name != null)
                packetDataStream.AddRange(Encoding.UTF8.GetBytes(name));


            if (message != null)
                packetDataStream.AddRange(Encoding.UTF8.GetBytes(message));

            return packetDataStream.ToArray();
        }

        #endregion

    }
}
