Action()
{
	web_set_timeout("STEP","360");
	web_set_timeout("CONNECT","360");
	web_set_timeout("RECEIVE","360");
	
	web_add_auto_header("ORIGPORT", "9999");
	web_add_auto_header("Content-Type", "application/json");
	web_add_auto_header("Authorization", "6cQjdz8Ks53L7s7405/WE/dnaXRau3wllWrQmM44f0GiUcGxOvXtavMQDVCNxhTO");
	web_add_auto_header("version", "[{\"ClientType\":\"2\",\"Version\":\"v2.0.0\"}]");

	web_add_auto_header("version", 
		"[{\"ClientType\":\"2\",\"Version\":\"v2.0.0\"}]");

	lr_think_time(35);
	
	lr_start_transaction("Login");


/*Correlation comment - Do not change!  Original value='2806d2a5-4f26-4f4b-94c3-08fbfc156961' Name ='Token' Type ='Manual'*/
	web_reg_save_param_json(
		"ParamName=Token",
		"QueryString=$.Token",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
		
	web_reg_save_param_json(
		"ParamName=TransactionResult",
		"QueryString=$.ResponseStatus.IsSuccess",
		SEARCH_FILTERS,
		"Scope=Body",
		"IgnoreRedirections=No",
		LAST);
		
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );
		
	web_custom_request("call_3", 
		"URL={URL}", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=", 
		"Snapshot=t80.inf", 
		"Mode=HTML", 
		"EncType=application/json; charset=UTF-8", 
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"2727e2136320e593a11077cb0fe0e90189f68526ad57a938f8b0649de592a668\",\"MenuId\":0,\"MethodType\":3,\"RoleId\":0,\"SessionToken\":\"\",\"TransactionName\":\"FirstLogin\",\"UserId\":0},\""
		"IsAstActivationLogin\":false,\"Pin\":\"E7x5hzKIiH2Sm04rJXrnig==\\n\",\"ReNewCaptcha\":false}", 
		LAST);
	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_4",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t81.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"3c606d92154145129bac347c40b8dbe09af838e01369b4d1e78d77ef32ef216f\",\"MenuId\":0,\"MethodType\":3,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"SecondLogin\",\"TwoFactorAuthenticationInfo\":{\"OtpPin\":\"\",\"SmsLogId\":0,\"SmsPin\":\"\"},\"UserId\":12336512917157585,\"UserName\":\"\"},\"Password\":\"E87re2gKWzeiGGQHOW76Gw==\\n"
		"\"}",
		LAST);
		
		lr_end_transaction("Login", LR_AUTO);
		lr_start_transaction("Havale");

		
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );
	
	web_custom_request("call_5",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t82.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"5486d4bf787acab04df50e56fea0b7b64b049c875f08cf6b6cad19ac16143ec1\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"SecurityStepsCheck\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"VersionControlforKVKK\":true}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );
	
	web_custom_request("call_6",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t83.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"d03acac43c8ab9fa342d1cfa812edfe562a59017706f8b426b27ce216b6cc989\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"GetMenuTree\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"MenuActionType\":0,\"MenuNameType\":2}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );
	
	web_custom_request("call_7",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t84.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"a16d5b9c4d98627a7fb0a7b22118cdd4fa9300a9ce4d3a4f78bdd6fc015f4ff5\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"ProfilePictureManagement\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"RequestType\":4}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );
	
	web_custom_request("call_8",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t85.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"bd5c66978aa83db37f2b3b4a0d73e599a0cc127ff3cb90d21e9ff028c93d3de5\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"RegisterPushDevice\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"Token\":\"dqYTlw9WtsA:APA91bFgrleWFm3Tu1kuqzTzuontPf32zo5lzwOn3ZFq6wFQ-LRk8s20XFnHbkt22WMPVGPvG74W16yNsAw0FdgITuQj4qcF_BlX3otIWS5k7dEapQbcT1cEJVaGkIREZ04TKpKANKfE\"}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );
	
	web_custom_request("call_9",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t86.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"9abc581c7d53d915c712cda26931d499b43972c6c14dd5b7b53a9a55f9a90389\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"WidgetData\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"WidgetType\":1}",
		LAST);

	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_10",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t87.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"9abc581c7d53d915c712cda26931d499b43972c6c14dd5b7b53a9a55f9a90389\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"WidgetData\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"WidgetType\":2}",
		LAST);
	

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_11",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t88.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"f6857409f15534c9c6398d64f800ac2e7883668d02230f21a556dae7fd5b4c8f\",\"MenuId\":2113,\"MethodType\":1,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"AccountList\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"FilterByListTransactions\":false,\"GetOnlyMergedInvestmentAccounts\":false,\"ThrowErrorOnEmptyList\":false}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );
	
	web_custom_request("call_12",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t89.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"869ac17653b797a8256490026ae8ba6722814f98b163407c9f27a60965b51e5d\",\"MenuId\":2113,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"AllAccountList\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"FilterByListTransactions\":false,\"GetOnlyMergedInvestmentAccounts\":false,\"ThrowErrorOnEmptyList\":false}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_13",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t90.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"BodyBinary={\"FetchDotMenu\":true,\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"d2e7e83b818af89ab784fb62d42a4be7d1cdb6f5b5d9171a93fbdcca19b87a57\",\"MenuId\":2113,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"AccountDetails\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"Account\":{\"AccountStatus\":0,\"AccountType\":1,\"AccountTypeDescription\":\"Vadesiz\",\"AdditionalNumber\":5001,\"ArrangedAccountName\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5001\",\"Balance\":{\"AvailableBalance\":0.0,\"AvailableBalanceWithoutKmh\":0.0,\"AvailableCashBalance\":0.0,\"AvailablePaymentBalance\":0.0,\"Balance\":0.0,\"KmhCashLimit\":0.0,\"KmhPaymentLimit\":0.0,\"LedgerBalance\":0.0,\"OverdraftAccountBalance\":0.0},\"Branch\":{\"CityCode\":0,\"Co"
		"de\":102,\"CodeAndName\":\"102 / \\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5001\",\"ClosedCode\":\"H\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR7600010001020{CUSTOMERID}5001\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,"
		"\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"2017-06-05T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Name\":\"\",\"Number\":\"102-{CUSTOMERID}-5001\",\"OpenDate\":\"2002-02-19T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ProductCode\":\"63\",\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":530,\"SkontNumber\":300000,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0}}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_14",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t91.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"487155333ec58c5188c220c438d89a7061306d37f71ae685d6460053eb8f723d\",\"MenuId\":1896,\"MethodType\":1,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"MoneyTransferToOtherAccount\",\"TwoFactorAuthenticationInfo\":{\"OtpPin\":\"\",\"SmsLogId\":0,\"SmsPin\":\"\"},\"UserId\":12336512917157585,\"UserName\":\"\"},\"AlternativeAccountUsage\":false,\"OverdraftAccountUsage\":false,\"SaveBeneficiary\":false,\"TransferRepeatCount\":0}",
		LAST);
	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_15",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t92.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ActualTransactionName\":\"MoneyTransferToOtherAccount\",\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"df03aa35b8ab573805c680eef443ab74d3e8a8ab6d1749a08677cbc713150453\",\"MenuId\":1896,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"BeneficiaryList\",\"UserId\":12336512917157585,\"UserName\":\"\"}}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_16",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t93.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"BodyBinary={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"5fdc0ba6f1ed4ed29ce6f36f30523de00adf367db94d9899328cad9d24e02922\",\"MenuId\":0,\"MethodType\":2,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"UpdateTransactionName\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"AlternativeAccountUsage\":false,\"Beneficiary\":{\"Account\":{\"AccountStatus\":0,\"AccountType\":0,\"AdditionalNumber\":5004,\"ArrangedAccountName\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"Bank\":{\"Code\":10,\"ID\":1,\"Name\":\"Ziraat Bankas\\xC4\\xB1\"},\"Branch\":{\"CityCode\":34,\"Code\":2487,\"CodeAndName\":\"2487 / \\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC4\\xB0STANBUL - "
		"TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR300001002487089772825004\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"0001-01-01T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAcco"
		"unt\":0,\"Number\":\"2487-8977282-5004\",\"OpenDate\":\"0001-01-01T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":0,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"AddSenderNameToDesc\":false,\"Address\":\"\",\"Birthday\":\"0001-01-01T00:00:00\",\"ChannelId\":3,\"Country\":{\"Code\":\"\"},\"CreateDate\":\"0001-01-01T00:00:00\",\"CreditCard\":{\"CurrentDebitForeignCurrencyView\":\"0,00 USD\",\"CurrentDebitLocalCurrencyView\":\"0,00 TL\",\"ExpireDate\":\"\",\"MaskedNumber\":\"\"},\"Description\":\"\",\"FullName\":\"EYUP \\xC3\\x87ORAP\\xC3\\x87IO\\xC4\\x9ELU\",\"HasAccess\":true,\"Id\":47995076,\"IsDefinedBeneficiary\":false,\"IsFrequentlyUsed\":false,\"IsQuickOperation\":false,\"Nick\":\"Eyup Ziraat\",\"OldCurrencyCode\":0,\"Order\":0,\"PhoneNumber\":\"\",\"SaveBeneficiary\":false,\"SwiftReasonCode\":0,\"TransferReasonName\":\"D\\xC4\\xB0\\xC4\\x9EER \\xC3\\x96DEMELER\",\"TransferType\":7,\"UseI"
		"ban\":false,\"UseKMH\":false},\"OverdraftAccountUsage\":false,\"SaveBeneficiary\":false}",
		LAST);
	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_17",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t94.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ActualTransactionName\":\"MoneyTransferToOtherAccount\",\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"f6857409f15534c9c6398d64f800ac2e7883668d02230f21a556dae7fd5b4c8f\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"AccountList\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"ControlID\":\"AccountListSelector_From\",\"CurrencyFilter\":2,\"FilterByListTransactions\":false,\"GetOnlyMergedInvestmentAccounts\":false,\"RelatedAccountType\":0,\"ThrowErrorOnEmptyList\":false}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_18",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t95.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ActualTransactionName\":\"MoneyTransferToOtherAccount\",\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"e555c02ff07f0eb550035cd99b92f80a1f8ea00b1735b5fad2c235598879f797\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"GetUserLimits\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"AddExecutingTransactionName\":true,\"CurrencyCode\":\"TRY\"}",
		LAST);
	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_19",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t96.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"BodyBinary={\"Header\":{\"ActualTransactionName\":\"MoneyTransferToOtherAccount\",\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"7788c0b5b24bf89e5f485f0b24ab16df46ab659d85ce9973c5a2ed715ffb205d\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"GetPopularAmounts\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"Currency\":\"TRY\",\"TransactionRequest\":{\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"487155333ec58c5188c220c438d89a7061306d37f71ae685d6460053eb8f723d\",\"Menu"
		"Id\":1896,\"MethodType\":1,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"MoneyTransferToOtherAccount\",\"TwoFactorAuthenticationInfo\":{\"OtpPin\":\"\",\"SmsLogId\":0,\"SmsPin\":\"\"},\"UserId\":12336512917157585,\"UserName\":\"\"},\"AlternativeAccountUsage\":false,\"Beneficiary\":{\"Account\":{\"AccountStatus\":0,\"AccountType\":0,\"AdditionalNumber\":5004,\"ArrangedAccountName\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"Bank\":{\"Code\":10,\"ID\":1,\"Name\":\"Ziraat Bankas\\xC4\\xB1\"},\"Branch\":{\"CityCode\":34,\"Code\":2487,\"CodeAndName\":\"2487 / \\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInve"
		"stmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR300001002487089772825004\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"0001-01-01T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Number\":\"2487-8977282-5004\",\"OpenDate\":\"0001-01-01T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":0,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"AddSenderNameToDes"
		"c\":false,\"Address\":\"\",\"Birthday\":\"0001-01-01T00:00:00\",\"ChannelId\":3,\"Country\":{\"Code\":\"\"},\"CreateDate\":\"0001-01-01T00:00:00\",\"CreditCard\":{\"CurrentDebitForeignCurrencyView\":\"0,00 USD\",\"CurrentDebitLocalCurrencyView\":\"0,00 TL\",\"ExpireDate\":\"\",\"MaskedNumber\":\"\"},\"Description\":\"\",\"FullName\":\"EYUP \\xC3\\x87ORAP\\xC3\\x87IO\\xC4\\x9ELU\",\"HasAccess\":true,\"Id\":47995076,\"IsDefinedBeneficiary\":false,\"IsFrequentlyUsed\":false,\"IsQuickOperation\":false,\"Nick\":\"Eyup Ziraat\",\"OldCurrencyCode\":0,\"Order\":0,\"PhoneNumber\":\"\",\"SaveBeneficiary\":false,\"SwiftReasonCode\":0,\"TransferReasonName\":\"D\\xC4\\xB0\\xC4\\x9EER \\xC3\\x96DEMELER\",\"TransferType\":7,\"UseIban\":false,\"UseKMH\":false},\"OverdraftAccountUsage\":false,\"SaveBeneficiary\":false,\"Sender\":{\"Account\":{\"AccountStatus\":0,\"AccountType\":1,\"AccountTypeDescription\":\"Vadesiz\",\"AdditionalNumber\":5005,\"ArrangedAccountName\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"Balance\":{\"Availa"
		"bleBalance\":10257.21,\"AvailableBalanceWithoutKmh\":0.0,\"AvailableCashBalance\":10257.21,\"AvailablePaymentBalance\":10257.21,\"Balance\":605.07,\"KmhCashLimit\":0.0,\"KmhPaymentLimit\":0.0,\"LedgerBalance\":10257.21,\"OverdraftAccountBalance\":10257.21},\"Branch\":{\"CityCode\":0,\"Code\":102,\"CodeAndName\":\"102 / \\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"ClosedCode\":\"H\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterest"
		"Rate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR6500010001020{CUSTOMERID}5005\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"2018-11-05T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Name\":\"\",\"Number\":\"102-{CUSTOMERID}-5005\",\"OpenDate\":\"2016-03-28T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ProductCode\":\"63\",\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":300000,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"FullName\":\"\\xC4\\xB0BRAH\\xC4\\xB0M G\\xC3\\x9CRCAN\",\"PhoneNumber\":\"\"},\"TransactionDate\":\"2018-12-10T13:57:17\",\"TransferRepeatCount\":0}}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );
	web_custom_request("call_20",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t97.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"BodyBinary={\"Header\":{\"ActualTransactionName\":\"MoneyTransferToOtherAccount\",\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"d7469eb94eb13b4aa9be91bb2fe6953640a9a1d501a01b3f44429d6c92a03af5\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"ValidateMoneyTransferToOtherAccount\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"Request\":{\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"487155333ec58c5188c220c438d89a7061306d37f71ae685d6460053eb8f723d\",\"MenuId\":1896,\"Me"
		"thodType\":1,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"MoneyTransferToOtherAccount\",\"TwoFactorAuthenticationInfo\":{\"OtpPin\":\"\",\"SmsLogId\":0,\"SmsPin\":\"\"},\"UserId\":12336512917157585,\"UserName\":\"\"},\"AlternativeAccountUsage\":false,\"Amount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":1.0},\"Beneficiary\":{\"Account\":{\"AccountStatus\":0,\"AccountType\":0,\"AdditionalNumber\":5004,\"ArrangedAccountName\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"Bank\":{\"Code\":10,\"ID\":1,\"Name\":\"Ziraat Bankas\\xC4\\xB1\"},\"Branch\":{\"CityCode\":34,\"Code\":2487,\"CodeAndName\":\"2487 / \\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalN"
		"umber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR300001002487089772825004\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"0001-01-01T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Number\":\"2487-8977282-5004\",\"OpenDate\":\"0001-01-01T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":0,\""
		"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"AddSenderNameToDesc\":false,\"Address\":\"\",\"Birthday\":\"0001-01-01T00:00:00\",\"ChannelId\":3,\"Country\":{\"Code\":\"\"},\"CreateDate\":\"0001-01-01T00:00:00\",\"CreditCard\":{\"CurrentDebitForeignCurrencyView\":\"0,00 USD\",\"CurrentDebitLocalCurrencyView\":\"0,00 TL\",\"ExpireDate\":\"\",\"MaskedNumber\":\"\"},\"Description\":\"\",\"FullName\":\"EYUP \\xC3\\x87ORAP\\xC3\\x87IO\\xC4\\x9ELU\",\"HasAccess\":true,\"Id\":47995076,\"IsDefinedBeneficiary\":false,\"IsFrequentlyUsed\":false,\"IsQuickOperation\":false,\"Nick\":\"Eyup Ziraat\",\"OldCurrencyCode\":0,\"Order\":0,\"PhoneNumber\":\"\",\"SaveBeneficiary\":false,\"SwiftReasonCode\":0,\"TransferReasonName\":\"D\\xC4\\xB0\\xC4\\x9EER \\xC3\\x96DEMELER\",\"TransferType\":7,\"UseIban\":false,\"UseKMH\":false},\"OverdraftAccountUsage\":false,\"SaveBeneficiary\":false,\"Sender\":{\"Account\":{\"AccountStatus\":0,\"AccountType\":1,\"AccountTypeDescription\":\"Vadesiz\",\"AdditionalNumb"
		"er\":5005,\"ArrangedAccountName\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"Balance\":{\"AvailableBalance\":10257.21,\"AvailableBalanceWithoutKmh\":0.0,\"AvailableCashBalance\":10257.21,\"AvailablePaymentBalance\":10257.21,\"Balance\":605.07,\"KmhCashLimit\":0.0,\"KmhPaymentLimit\":0.0,\"LedgerBalance\":10257.21,\"OverdraftAccountBalance\":10257.21},\"Branch\":{\"CityCode\":0,\"Code\":102,\"CodeAndName\":\"102 / \\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"ClosedCode\":\"H\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\""
		"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR6500010001020{CUSTOMERID}5005\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"2018-11-05T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Name\":\"\",\"Number\":\"102-{CUSTOMERID}-5005\",\"OpenDate\":\"2016-03-28T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ProductCode\":\"63\",\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":300000,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"FullName\":\"\\xC4\\xB0BRAH\\xC4\\xB0M G\\xC3\\x9CRCAN\",\"PhoneNumber\":\"\"},\"TransactionDate\":\"2018-12-10T13:57:17"
		"\",\"TransferRepeatCount\":0},\"Step\":1}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_21",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t98.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"BodyBinary={\"Header\":{\"ActualTransactionName\":\"MoneyTransferToOtherAccount\",\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"29cacea5ec5437f68aef3f2053a4e80b26bc9985dd99d52d4a48007c96bdd837\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"MoneyTransferConfirmation\",\"TwoFactorAuthenticationInfo\":{\"OtpPin\":\"\",\"SmsLogId\":0,\"SmsPin\":\"\"},\"UserId\":12336512917157585,\"UserName\":\"\"},\"AlternativeAccountUsage\":false,\"Amount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":1.0},\"Beneficiary\":{\"Account\":{\"AccountStatus\":0,\"AccountType\":0,\"AdditionalNumber\":5004,\"ArrangedAccountName\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"Bank\":{\"Code\":10,\"ID\":1,\"N"
		"ame\":\"Ziraat Bankas\\xC4\\xB1\"},\"Branch\":{\"CityCode\":34,\"Code\":2487,\"CodeAndName\":\"2487 / \\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR300001002487089772825004\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedTo"
		"Custodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"0001-01-01T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Number\":\"2487-8977282-5004\",\"OpenDate\":\"0001-01-01T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":0,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"AddSenderNameToDesc\":false,\"Address\":\"\",\"Birthday\":\"0001-01-01T00:00:00\",\"ChannelId\":3,\"Country\":{\"Code\":\"\"},\"CreateDate\":\"0001-01-01T00:00:00\",\"CreditCard\":{\"CurrentDebitForeignCurrencyView\":\"0,00 USD\",\"CurrentDebitLocalCurrencyView\":\"0,00 TL\",\"ExpireDate\":\"\",\"MaskedNumber\":\"\"},\"Description\":\"Y\\xC3\\xBCk testi\",\"FullName\":\"EYUP \\xC3\\x87ORAP\\xC3\\x87IO\\xC4\\x9ELU\",\"HasAccess\":true,\"Id\":47995076,\"IsDefinedBeneficiary\":false,\"IsFreque"
		"ntlyUsed\":false,\"IsQuickOperation\":false,\"Nick\":\"Eyup Ziraat\",\"OldCurrencyCode\":0,\"Order\":0,\"PhoneNumber\":\"\",\"SaveBeneficiary\":false,\"SwiftReasonCode\":0,\"TransferReasonName\":\"D\\xC4\\xB0\\xC4\\x9EER \\xC3\\x96DEMELER\",\"TransferReasonType\":99,\"TransferType\":7,\"UseIban\":false,\"UseKMH\":false},\"OverdraftAccountUsage\":false,\"SaveBeneficiary\":false,\"Sender\":{\"Account\":{\"AccountStatus\":0,\"AccountType\":1,\"AccountTypeDescription\":\"Vadesiz\",\"AdditionalNumber\":5005,\"ArrangedAccountName\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"Balance\":{\"AvailableBalance\":10257.21,\"AvailableBalanceWithoutKmh\":0.0,\"AvailableCashBalance\":10257.21,\"AvailablePaymentBalance\":10257.21,\"Balance\":605.07,\"KmhCashLimit\":0.0,\"KmhPaymentLimit\":0.0,\"LedgerBalance\":10257.21,\"OverdraftAccountBalance\":10257.21},\"Branch\":{\"CityCode\":0,\"Code\":102,\"CodeAndName\":\"102 / \\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\""
		":false,\"Name\":\"\\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"ClosedCode\":\"H\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR6500010001020{CUSTOMERID}5005\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"2018-"
		"11-05T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Name\":\"\",\"Number\":\"102-{CUSTOMERID}-5005\",\"OpenDate\":\"2016-03-28T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ProductCode\":\"63\",\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":300000,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"FullName\":\"\\xC4\\xB0BRAH\\xC4\\xB0M G\\xC3\\x9CRCAN\",\"PhoneNumber\":\"\"},\"TransactionDate\":\"2018-12-10T00:00:00\",\"TransferRepeatCount\":0}",
		LAST);
	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_22",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t99.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"BodyBinary={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"5ca6f5ebf99623ca75480fba05a0f4367f21bf0a189043a3f58eb60ef62c10d3\",\"MenuId\":0,\"MethodType\":2,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"IntrabankToOtherAccounts\",\"TwoFactorAuthenticationInfo\":{\"OtpPin\":\"\",\"SmsLogId\":0,\"SmsPin\":\"\"},\"UserId\":12336512917157585,\"UserName\":\"\"},\"AlternativeAccountUsage\":false,\"Amount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":1.0},\"Beneficiary\":{\"Account\":{\"AccountStatus\":0,\"AccountType\":0,\"AdditionalNumber\":5004,\"ArrangedAccountName\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"Bank\":{\"Code\":10,\"ID\":1,\"Name\":\"Ziraat Bankas\\xC4\\xB1\"},\"Branch\":{\"CityCode\""
		":34,\"Code\":2487,\"CodeAndName\":\"2487 / \\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR300001002487089772825004\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":fa"
		"lse,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"0001-01-01T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Number\":\"2487-8977282-5004\",\"OpenDate\":\"0001-01-01T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":0,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"AddSenderNameToDesc\":false,\"Address\":\"\",\"Birthday\":\"0001-01-01T00:00:00\",\"ChannelId\":3,\"Country\":{\"Code\":\"\"},\"CreateDate\":\"0001-01-01T00:00:00\",\"CreditCard\":{\"CurrentDebitForeignCurrencyView\":\"0,00 USD\",\"CurrentDebitLocalCurrencyView\":\"0,00 TL\",\"ExpireDate\":\"\",\"MaskedNumber\":\"\"},\"Description\":\"Y\\xC3\\xBCk testi\",\"FullName\":\"EYUP \\xC3\\x87ORAP\\xC3\\x87IO\\xC4\\x9ELU\",\"HasAccess\":true,\"Id\":47995076,\"IsDefinedBeneficiary\":false,\"IsFrequentlyUsed\":false,\"IsQuickOperation\":false,\"Nick\":\"Eyup"
		" Ziraat\",\"OldCurrencyCode\":0,\"Order\":0,\"PhoneNumber\":\"\",\"SaveBeneficiary\":false,\"SwiftReasonCode\":0,\"TransferReasonName\":\"D\\xC4\\xB0\\xC4\\x9EER \\xC3\\x96DEMELER\",\"TransferReasonType\":99,\"TransferType\":7,\"UseIban\":false,\"UseKMH\":false},\"OverdraftAccountUsage\":false,\"SaveBeneficiary\":false,\"ScheduledTransfers\":[{\"Amount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":1.0},\"EFTMessageAmount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":0.0},\"ExpenseAmount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":0.0},\"ExpenseBSMVAmount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":0.0},\"ExpenseCommissionAmount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":0.0},\"IsOrder\":false,\"LogId\":0,\"TransactionDate\":\"2018-12-10T00:00:00\"}],\"Sender\":{\"Account\":{\"Acc"
		"ountStatus\":0,\"AccountType\":1,\"AccountTypeDescription\":\"Vadesiz\",\"AdditionalNumber\":5005,\"ArrangedAccountName\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"Balance\":{\"AvailableBalance\":10257.21,\"AvailableBalanceWithoutKmh\":0.0,\"AvailableCashBalance\":10257.21,\"AvailablePaymentBalance\":10257.21,\"Balance\":605.07,\"KmhCashLimit\":0.0,\"KmhPaymentLimit\":0.0,\"LedgerBalance\":10257.21,\"OverdraftAccountBalance\":10257.21},\"Branch\":{\"CityCode\":0,\"Code\":102,\"CodeAndName\":\"102 / \\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"ClosedCode\":\"H\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"C"
		"reditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR6500010001020{CUSTOMERID}5005\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"2018-11-05T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Name\":\"\",\"Number\":\"102-{CUSTOMERID}-5005\",\"OpenDate\":\"2016-03-28T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ProductCode\":\"63\",\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":300000,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"FullName\":\"\\xC4\\xB0BRAH\\xC4"
		"\\xB0M G\\xC3\\x9CRCAN\",\"PhoneNumber\":\"\"},\"TransactionDate\":\"2018-12-10T00:00:00\",\"TransferRepeatCount\":0}",
		LAST);
	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_23",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t100.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"BodyBinary={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"5ca6f5ebf99623ca75480fba05a0f4367f21bf0a189043a3f58eb60ef62c10d3\",\"MenuId\":0,\"MethodType\":3,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"IntrabankToOtherAccounts\",\"TwoFactorAuthenticationInfo\":{\"OtpPin\":\"\",\"SmsLogId\":0,\"SmsPin\":\"\"},\"UserId\":12336512917157585,\"UserName\":\"\"},\"AlternativeAccountUsage\":false,\"Amount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":1.0},\"Beneficiary\":{\"Account\":{\"AccountStatus\":0,\"AccountType\":0,\"AdditionalNumber\":5004,\"ArrangedAccountName\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"Bank\":{\"Code\":10,\"ID\":1,\"Name\":\"Ziraat Bankas\\xC4\\xB1\"},\"Branch\":{\"CityCode\""
		":34,\"Code\":2487,\"CodeAndName\":\"2487 / \\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC4\\xB0STANBUL - TEKNOPARK/\\xC4\\xB0STANBUL \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC4\\xB0STANBUL - TEKNOPARK - 5004\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"CreditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR300001002487089772825004\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":fa"
		"lse,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"0001-01-01T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Number\":\"2487-8977282-5004\",\"OpenDate\":\"0001-01-01T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":0,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"AddSenderNameToDesc\":false,\"Address\":\"\",\"Birthday\":\"0001-01-01T00:00:00\",\"ChannelId\":3,\"Country\":{\"Code\":\"\"},\"CreateDate\":\"0001-01-01T00:00:00\",\"CreditCard\":{\"CurrentDebitForeignCurrencyView\":\"0,00 USD\",\"CurrentDebitLocalCurrencyView\":\"0,00 TL\",\"ExpireDate\":\"\",\"MaskedNumber\":\"\"},\"Description\":\"Y\\xC3\\xBCk testi\",\"FullName\":\"EYUP \\xC3\\x87ORAP\\xC3\\x87IO\\xC4\\x9ELU\",\"HasAccess\":true,\"Id\":47995076,\"IsDefinedBeneficiary\":false,\"IsFrequentlyUsed\":false,\"IsQuickOperation\":false,\"Nick\":\"Eyup"
		" Ziraat\",\"OldCurrencyCode\":0,\"Order\":0,\"PhoneNumber\":\"\",\"SaveBeneficiary\":false,\"SwiftReasonCode\":0,\"TransferReasonName\":\"D\\xC4\\xB0\\xC4\\x9EER \\xC3\\x96DEMELER\",\"TransferReasonType\":99,\"TransferType\":7,\"UseIban\":false,\"UseKMH\":false},\"OverdraftAccountUsage\":false,\"SaveBeneficiary\":false,\"ScheduledTransfers\":[{\"Amount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":1.0},\"EFTMessageAmount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":0.0},\"ExpenseAmount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":0.0},\"ExpenseBSMVAmount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":0.0},\"ExpenseCommissionAmount\":{\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"Value\":0.0},\"IsOrder\":false,\"LogId\":0,\"TransactionDate\":\"2018-12-10T00:00:00\"}],\"Sender\":{\"Account\":{\"Acc"
		"ountStatus\":0,\"AccountType\":1,\"AccountTypeDescription\":\"Vadesiz\",\"AdditionalNumber\":5005,\"ArrangedAccountName\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"Balance\":{\"AvailableBalance\":10257.21,\"AvailableBalanceWithoutKmh\":0.0,\"AvailableCashBalance\":10257.21,\"AvailablePaymentBalance\":10257.21,\"Balance\":605.07,\"KmhCashLimit\":0.0,\"KmhPaymentLimit\":0.0,\"LedgerBalance\":10257.21,\"OverdraftAccountBalance\":10257.21},\"Branch\":{\"CityCode\":0,\"Code\":102,\"CodeAndName\":\"102 / \\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"IsEftCreditCardTransferBranch\":false,\"Name\":\"\\xC5\\x9EARK\\xC3\\x96Y/TEK\\xC4\\xB0RDA\\xC4\\x9E \\xC5\\x9EUBES\\xC4\\xB0\",\"TypeCode\":0},\"BranchNameAndAccountAdditionNumber\":\"\\xC5\\x9EARK\\xC3\\x96Y - 5005\",\"ClosedCode\":\"H\",\"ConnectedAccountBranchCode\":0,\"ConnectedAdditionalNumber\":0,\"ConnectedBranchNameAndAccountAdditionNumber\":\"\",\"ConnectedBranchNameAndInvestmentAdditionNumber\":\"\",\"CreditAccountType\":0,\"C"
		"reditMaturityDate\":\"0001-01-01T00:00:00\",\"CreditType\":0,\"CumulativeInterest\":0,\"Currency\":{\"Code\":\"TRY\",\"Index\":0,\"Default\":false,\"Name\":\"TL\"},\"ExtraInterestRate\":0.0,\"HoldAmount\":0,\"IBAN\":\"TR6500010001020{CUSTOMERID}5005\",\"InterestBeginDate\":\"0001-01-01T00:00:00\",\"InterestDuration\":0,\"InterestEndAmount\":0.0,\"InterestEndDate\":\"0001-01-01T00:00:00\",\"InterestRate\":0.0,\"IsConnectedToCustodian\":false,\"IsFrequentlyUsed\":false,\"IsLoyal\":false,\"IsMusterek\":false,\"IsMusterekAccount\":false,\"IsOverdraftAccount\":false,\"KMHTypeCode\":0,\"LastTransactionDate\":\"2018-11-05T00:00:00\",\"LiquidFundAmount\":0.0,\"MainCreditAccount\":0,\"Name\":\"\",\"Number\":\"102-{CUSTOMERID}-5005\",\"OpenDate\":\"2016-03-28T00:00:00\",\"OpenedChannel\":0,\"OverdraftLimit\":0.0,\"ProductCode\":\"63\",\"ReimbursementAdditionalNumber\":0,\"RetiredInstitutionCode\":0,\"SkontNumber\":300000,\"TimeDepositAccountTypeValue\":0,\"UcdSiraNo\":0,\"UtilizationType\":0},\"FullName\":\"\\xC4\\xB0BRAH\\xC4"
		"\\xB0M G\\xC3\\x9CRCAN\",\"PhoneNumber\":\"\"},\"TransactionDate\":\"2018-12-10T00:00:00\",\"TransferRepeatCount\":0}",
		LAST);
	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_24",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t101.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ActualTransactionName\":\"MoneyTransferToOtherAccount\",\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"b9d41d125187a43b293e5d925051ad086918edb524ac016dff8d3327b4589214\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"GetAccountAvailableBalance\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"AccountAdditionalNumber\":0,\"AccountNumber\":\"102-{CUSTOMERID}-5005\",\"CustomerId\":{CUSTOMERID}}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_25",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t102.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"a07bc44220a8bdcac8661ae019b524c68d7c830dfd631ca3dc180144783e4389\",\"MenuId\":1896,\"MethodType\":3,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"SendReceiptWithMail\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"IsAsync\":true,\"MailInfo\":{\"BBC\":\"\",\"CC\":\"\",\"CustomerID\":\"{CUSTOMERID}\",\"MailFormat\":\"1\",\"Message\":\"DEKONT MESAJ\",\"Subject\":\"DEKONT\",\"To\":\"dbolatli@ziraatteknoloji.com\"},\"ReceiptInfo\":{\"AdditionalNumber\":5005,\"BranchCode\":102,\"CustomerID\":\"{CUSTOMERID}\",\"ReceiptDate\":\"2018-12-10T00:00:00\",\"Reference\":\"F00002\"}}",
		LAST);

	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_26",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t103.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"9abc581c7d53d915c712cda26931d499b43972c6c14dd5b7b53a9a55f9a90389\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"WidgetData\",\"UserId\":12336512917157585,\"UserName\":\"\"},\"WidgetType\":1}",
		LAST);
	lr_end_transaction("Havale", LR_AUTO);

	
	web_reg_find("Text/IC=\"IsSuccess\":false", "Fail=Found", LAST );

	web_custom_request("call_27",
		"URL={URL}",
		"Method=POST",
		"Resource=0",
		"RecContentType=application/json",
		"Referer=",
		"Snapshot=t104.inf",
		"Mode=HTML",
		"EncType=application/json; charset=UTF-8",
		"Body={\"Header\":{\"ChannelType\":11,\"ClientIp\":\"127.0.0.1\",\"ClientType\":\"2\",\"Culture\":0,\"CustomerId\":\"{CUSTOMERID}\",\"CustomerType\":0,\"DeviceUniqueId\":\"aa394761-e36d-3012-b6d2-0d8b9f06d9de\",\"IsSecureLoginVersion\":true,\"IsSecurityStepVersion\":true,\"IsTwoFactorTransaction\":false,\"Key\":\"db587609a622544f99ce1328e9b3f5830c6e0bffd8241f7d992421f739fdbadf\",\"MenuId\":0,\"MethodType\":4,\"RoleId\":1,\"SessionToken\":\"{Token}\",\"TransactionName\":\"MobileLogOff\",\"UserId\":12336512917157585,\"UserName\":\"\"}}",
		LAST);

	return 0;
}