// �������幬� /d/city/chuzhou/shangqinggong.c
// by lala, 1997-12-06

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"���幬"NOR);
    set("long", @LONG
���幬����һ�����ʢ�Ĵ���ۡ�����ÿ�춼�гɰ���ǧ����ǰ���ʼ��ף�
���ӡ���Щ�����������һ���־�����ǧ�������ӵľ��������Թ�����ĵ�ʿ
Ҳһ����������⡣������˵������������ʮ�����飬������ĵ�ʿ��������
ʮ���ֵ�׼��
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "west"      : __DIR__"qingyun_lu",
    ]));
    set("objects", ([
        __DIR__"npc/daoshi" :   1,
        __DIR__"npc/daoshi2":   1,
    ]));
    setup();
}

    