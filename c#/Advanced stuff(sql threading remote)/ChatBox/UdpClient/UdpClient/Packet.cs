using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UdpClient
{

    public enum DataIdentifier
    {
        Message,
        LogIn,
        LogOut,
        Null
    }

    class Packet
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
            this.dataIdentifier = DataIdentifier.Null;
            this.message = null;
            this.name = null;
        }
    }
}
