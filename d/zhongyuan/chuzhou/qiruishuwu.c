//������������ /d/city/chuzhou/qiruishuwu.c

inherit ROOM;

#include <ansi.h>

void create()
{
    set("short", YEL"��������"NOR);
    set("long", @LONG
����ʵ�������Ķ��Ǿ��飬�𿴲����鶼�������õ��ˣ����Ǿ�˵��������
���з����䱾�����Ҽ�Ǯ�ǳ����ˡ��������в���������ˣ�Ҳ�кܶ���˲���
���飬ֻ��վ�����￴�����ݵ��ϰ�Ҳ���������ǣ��������Ƿ�����
LONG
    );
    set("no_kill",  "yangzhou");
    set("exits", ([
        "southeast" : __DIR__"qingyun_lu",
        ]));
    set("objects", ([
        __DIR__"npc/bookboss"   :   1,
        __DIR__"npc/reader"     :   random(2),
    ]));        
    setup();
}
