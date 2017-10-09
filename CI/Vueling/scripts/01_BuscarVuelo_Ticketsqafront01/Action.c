/*
Parámetros del script
=====================

Obtenidos a partir de hojas de datos
	* p_URLMain           -> URL principal a la que el script hace las peticiones

	* p_AeropuertoDestino -> Código del aeropuerto de destino
	* p_AeropuertoOrigen  -> Código del aeropuerto de origen
	* p_Destino           -> Ciudad de destino
	* p_Origen            -> Ciudad de origen.
	
	* p_NumeroDeAdultos   -> Numero de personas adultas interesadas en buscar vuelo
	
	* p_Tarifa 			  -> Tipo de tarifa aplicada (basic, optima o excellence)
	* p_TarifaId	      -> Identificador de dicha tarifa
	
	* p_TipoViaje		  -> Tipo de viaje a buscar (Sólo ida o ida y vuelta)
	
Valores numéricos aleatorios
	* p_p_DaysFuture
	* p_OffsetVuelta

*/

Action()
{
	
	//Ida
	lr_save_datetime("%Y-%m-%d", DATE_NOW + ONE_DAY * atoi(lr_eval_string("{p_DaysFuture}")), "p_FechaIda");
	lr_save_datetime("%Y-%m", DATE_NOW + ONE_DAY * atoi(lr_eval_string("{p_DaysFuture}")), "p_AnoMesIda");
	lr_save_datetime("%d", DATE_NOW + ONE_DAY * atoi(lr_eval_string("{p_DaysFuture}")), "p_DiaIda");

	//Vuelta
	lr_save_datetime("%Y-%m-%d", DATE_NOW + ONE_DAY * (atoi(lr_eval_string("{p_DaysFuture}")) + atoi(lr_eval_string("{p_OffsetVuelta}"))), "p_FechaVuelta");
	lr_save_datetime("%Y-%m", DATE_NOW + ONE_DAY * (atoi(lr_eval_string("{p_DaysFuture}")) + atoi(lr_eval_string("{p_OffsetVuelta}"))), "p_AnoMesVuelta");
	lr_save_datetime("%d", DATE_NOW + ONE_DAY * (atoi(lr_eval_string("{p_DaysFuture}")) + atoi(lr_eval_string("{p_OffsetVuelta}"))), "p_DiaVuelta");

	lr_start_transaction("01_99_BuscarVuelo_Ticketsqafront01");

	lr_start_transaction("01_01_CargarURL_Ticketsqafront01");
	
	web_set_sockets_option("SSL_VERSION","TLS");
	
	/* Correlation comment - Do not change!  Original value='/wEPDwUBMGRkIDAvynEuRHfWRav0hQXNgUeddS0=' Name ='p_ViewState' Type ='Manual' */
	web_reg_save_param_regexp(
		"ParamName=p_ViewState",
		"RegExp=input id=\"viewState\" type=\"hidden\" value=\"([^\"]+)\"",
		// "Ordinal=3",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		"RequestUrl=*/*",
		LAST);		
	
	web_url("{p_URLMain}", 
		"URL={p_URLMain}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
//		EXTRARES, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/body.png", ENDITEM, 
//		"Url=https://vueling.inbenta.com/assets/css/inbenta.css?20160603", ENDITEM, 
//		"Url=https://vueling.inbenta.com/assets/js/inbenta.js?20160603&l=es&p=1", ENDITEM, 
//		"Url=https://connect.facebook.net/en_US/fbevents.js", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/selectArrow.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/vertical_whiteDot.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/css/VuelingBase/fonts/p022013t-webfont.eot?", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/sprite_graficos.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/sprite_iconografia.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/css/VuelingBase/fonts/p022014t-webfont.eot?", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/downArrow.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/buscador_icoPlaneVuelta.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/buscador_icoPlaneIda.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/global_sprite_colors.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/solidLineFooter.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/btnSmallArrow_white.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/loading.gif", ENDITEM, 
//		"Url=https://ssl.google-analytics.com/analytics.js", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/calendar.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/hint-bg.png", ENDITEM, 
//		"Url=https://www.google-analytics.com/collect?v=1&_v=j44&a=353329756&t=pageview&_s=1&dl=https%3A%2F%2Fticketsqafront01.vueling.com%2F&ul=es-es&de=utf-8&dt=Vueling&sd=24-bit&sr=1920x1080&vp=1920x986&je=1&_u=AACAAAQAI~&jid=&cid=2112283174.1462452219&tid=UA-117815-1&z=1434197413", ENDITEM, 
//		"Url=https://pubcache.vueling.com/Vueling.Cache.WCF.REST.WebService/BlankDaysService.svc/Get?callback=SKYSALES_Util_checkRoutesAndPromoUniversalDepartureCallback&departure=MAD&arrival=BCN&year=2016&month=8&monthsRange=24&_=1470816301269", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/calendar_travelTime_bg.png", ENDITEM, 
//		"Url=https://static.vueling.com/skysales/images/VuelingBase/calendar_travelTime--end_bg.png", ENDITEM, 
		LAST);	
	
	lr_end_transaction("01_01_CargarURL_Ticketsqafront01",LR_AUTO);

	lr_think_time(5);

	lr_start_transaction("01_02_BuscarVuelo_Ticketsqafront01");
	
	/* Correlation comment - Do not change!  Original value='/wEPDwUBMGQYAQUeX19Db250cm9sc1JlcXVpcmVQb3N0QmFja0tleV9fFgEFVUNvbnRyb2xHcm91cFNjaGVkdWxlU2VsZWN0VmlldyRBdmFpbGFiaWxpdHlJbnB1dFNjaGVkdWxlU2VsZWN0VmlldyRibG9ja1ByaWNlQ2hlY2tib3jRmzCKBE0pLTK4bG40ojZ93G6B+w==' Name ='p_ViewState2' Type ='Manual' */
	web_reg_save_param_regexp(
		"ParamName=p_ViewState2",
		"RegExp=id=\"viewState\" type=\"hidden\" value=\"([^\"]+)\"",
		// "Ordinal=3",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=Yes",
		"RequestUrl=*/Search.aspx*",
		LAST);

	web_submit_data("search.aspx", 
//		"Action={p_URLMain}/search.aspx", 
	    "Action=https://tickets.vueling.com/XmlSearch.aspx",
		"Method=POST", 
		"TargetFrame=",
		"RecContentType=text/html",		
		"Referer={p_URLMain}", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=__EVENTTARGET", "Value=AvailabilitySearchInputSearchView$LinkButtonNewSearch", ENDITEM, 
		"Name=__EVENTARGUMENT", "Value=", ENDITEM, 
		"Name=__VIEWSTATE", "Value={p_ViewState}", ENDITEM, 
		"Name=pageToken", "Value=", ENDITEM, 
		"Name=StaticHeaderViewSearchView$MemberLoginHeaderSearchView$TextBoxUserID", "Value=", ENDITEM, 
		"Name=StaticHeaderViewSearchView$MemberLoginHeaderSearchView$PasswordFieldPassword", "Value=", ENDITEM, 
		"Name=StaticHeaderViewSearchView$MemberlogoutHeaderSearchView$RedirectInput", "Value=default", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$RadioButtonMarketStructure", "Value={p_TipoViaje}", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$TextBoxMarketOrigin1", "Value={p_Origen}", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$TextBoxMarketDestination1", "Value={p_Destino}", ENDITEM, 
		"Name=date_picker", "Value={p_FechaIda}", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$DropDownListMarketDay1", "Value={p_DiaIda}", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$DropDownListMarketMonth1", "Value={p_AnoMesIda}", ENDITEM, 
		"Name=date_picker", "Value={p_FechaVuelta}", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$DropDownListMarketDay2", "Value={p_DiaVuelta}", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$DropDownListMarketMonth2", "Value={p_AnoMesVuelta}", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$TextBoxMarketOrigin2", "Value=Origen", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$TextBoxMarketDestination2", "Value=Destino", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$DropDownListPassengerType_ADT", "Value={p_NumeroDeAdultos}", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$DropDownListPassengerType_CHD", "Value=0", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$DropDownListPassengerType_INFANT", "Value=0", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$ResidentFamNumSelector", "Value=", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$ExtraSeat", "Value=", ENDITEM, 
		"Name=AvailabilitySearchInputSearchView$DropDownListSearchBy", "Value=columnView", ENDITEM, 
		"Name=departureStationCode1", "Value={p_AeropuertoOrigen}", ENDITEM, 
		"Name=arrivalStationCode1", "Value={p_AeropuertoDestino}", ENDITEM, 
		"Name=ErroneousWordOrigin1", "Value=", ENDITEM, 
		"Name=SelectedSuggestionOrigin1", "Value=", ENDITEM, 
		"Name=ErroneousWordDestination1", "Value=", ENDITEM, 
		"Name=SelectedSuggestionDestination1", "Value=", ENDITEM, 
		"Name=departureStationCode2", "Value=", ENDITEM, 
		"Name=arrivalStationCode2", "Value=", ENDITEM, 
		"Name=ErroneousWordOrigin2", "Value=", ENDITEM, 
		"Name=SelectedSuggestionOrigin2", "Value=", ENDITEM, 
		"Name=ErroneousWordDestination2", "Value=", ENDITEM, 
		"Name=SelectedSuggestionDestination2", "Value=", ENDITEM, 
		LAST);

	lr_end_transaction("01_02_BuscarVuelo_Ticketsqafront01",LR_AUTO);
	
	lr_end_transaction("01_99_BuscarVuelo_Ticketsqafront01",LR_AUTO);

	return 0;
	
}