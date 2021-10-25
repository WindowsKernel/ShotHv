#pragma once

/*
	APC�ȼ����µ�ȫ�߼��ں˵��÷ַ�
*/
_IRQL_requires_max_(APC_LEVEL)
NTSTATUS
WINAPI
UtilForEachProcessor(
	_In_ NTSTATUS(*callback_routine)(void*),
	_In_opt_ void* context
);

/*
	DPC�ȼ���ȫ�߼��ں˵��÷ַ�
*/
_IRQL_requires_max_(DISPATCH_LEVEL)
NTSTATUS
WINAPI
UtilForEachProcessorDpc(
	_In_ PKDEFERRED_ROUTINE deferred_routine,
	_In_opt_ void* context
);

_IRQL_requires_max_(DISPATCH_LEVEL)
VOID
WINAPI
UtilGetSelectorInfoBySelector(
	ULONG_PTR selector,
	ULONG_PTR* base,
	ULONG_PTR* limit,
	ULONG_PTR* attribute
);

/*
	ע��ػ��ص�
*/
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
WINAPI
RegisterShutdownCallBack(
	_In_ NTSTATUS (*ShutDownCallBack)(_In_ PDEVICE_OBJECT, _In_ PIRP)
);

/*
	ж�عػ��ص�
*/
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
WINAPI
UnRegisterShutdownCallBack();

BOOLEAN 
WINAPI 
BuildShellCode1(
	_Inout_ PHOOK_SHELLCODE1 pThunk, 
	_In_	ULONG64 Pointer
);

ULONG64
WINAPI
UtilPhysicalAddressToVirtualAddress(
	_In_ ULONG64 PhysicalAddress
);

ULONG64
WINAPI
UtilVirtualAddressToPhysicalAddress(
	IN ULONG64 VrtualAddress
);