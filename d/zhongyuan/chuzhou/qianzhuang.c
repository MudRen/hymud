// ����Ǯׯ /d/city/chuzhou/qianzhuang.c
// by lala, 1997-12-03

inherit BANK;
#include <ansi.h>

void create()
{
    set("short", YEL"Ǯׯ"NOR);
    set("long", @LONG
�����ǳ��ݵ�Ǯׯ����Ϊ���ݵش���ˮ������˺ӵĽ��㴦������ˮ·����
��������ҵ�൱������ص��̺Ŷ�����������Ǯ������Ǯׯ���кܶ����ڴ�ȡ
Ǯ��Ҳ�����ڶһ�������������ô���Ǯ�ƹ�����ȥ�����������۲�����Ǯׯ��
����ڸߴ�ĺ�ľ��̨����æ�����ݵ�Ӧ�����ˡ�
LONG
    );
    set("no_kill", "yangzhou");
    set("exits", ([
        "west"      : __DIR__"beishi",
        ]));
    set("objects", ([
        __DIR__"npc/bankboss"   :   1,
    ]));        
    setup();
}
