#include <stdio.h>
#include <stdlib.h>
#include <QtDBus/QtDBus>

#include "TC_Common.h"
#include "TC_ClientAdaptor.h"


void TestCaseClientAdaptor::workFinishedSlot(const QByteArray &)
{
	printf("tCaseClientAdaptor::workFinishedSlot\n");
}
