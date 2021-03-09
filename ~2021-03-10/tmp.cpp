MetroTreeNode* init_metro_data()
{
	std::ifstream jsonFile("metro.json");
	
	Json::Value jsonData;
	Json::CharReaderBuilder jsonReader;
	std::string err;

	if(Json::parseFromStream(jsonReader, jsonFile, &jsonData, &err)) {
		Json::Value metroData = jsonData;

		for(auto metro : metroData) {
			std::string station_name = metro["station_name"].asString();
			int station_code = metro["station_code"].asInt(); 
            int line = departureInfo["line"].asInt(); 
            int mnt = departureInfo["mnt"].asInt(); 

			Metro metroObj = Metro(station_name, station_code);

			for(auto departureInfo : metro["departure_info"]) {
				int destination_code = departureInfo["destination_code"].asInt(); 
				int departure_time = departureInfo["departure_time"].asInt();

				Departure scheduleObj = Departure(destination_code, line, departure_time);
				metroObj.insert_departure_info(scheduleObj);
			}

			metroObjs.push_back(metroObj);
		}
	}
	else
		std::cerr << "Failed to parse Json";
	
//	for(auto obj : metroObjs) {
//		obj.print();
//	}

    // metro 파일을 읽어 tree구조로 저장한다.
	MetroTreeNode* temp;
	return temp;
}
