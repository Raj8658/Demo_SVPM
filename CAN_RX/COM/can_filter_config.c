void can_filter_config(void){

	CAN_FilterTypeDef can_filter;
	can_filter.FilterActivation = ENABLE;
	can_filter.FilterBank = 0;
	can_filter.FilterFIFOAssignment = CAN_FilterFIFO0;
	can_filter.FilterIdHigh = 0x0000;
	can_filter.FilterIdLow = 0x0000;
	can_filter.FilterMaskIdHigh = 0x0000;
	can_filter.FilterMaskIdLow = 0x0000;
	can_filter.FilterMode = CAN_FILTERMODE_IDMASK;
	can_filter.FilterScale = CAN_FILTERSCALE_32BIT;

	HAL_CAN_ConfigFilter(&hcan2, &can_filter);

}