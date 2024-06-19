void CAN_TX(void){

	   uint32_t Tx_mailBox;
       CAN_TxHeaderTypeDef Tx;

       Tx.DLC = 5;
       Tx.IDE = CAN_ID_STD;
       Tx.RTR = CAN_RTR_DATA;
       Tx.StdId = 0x666;

       uint8_t data[5] = {'H','L','L','E','O'};

       if (HAL_CAN_AddTxMessage(&hcan2, &Tx, data, &Tx_mailBox)!=HAL_OK){

    	   Error_Handler();
       }

}