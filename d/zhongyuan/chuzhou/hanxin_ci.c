// ���ݺ������ /d/city/chuzhou/hanxin_ci.c
// by lala, 1997-12-05

inherit ROOM;
#include <ansi.h>

void create()
{
    set("short", WHT"������"NOR);
    set("long", @LONG
����Ϊ��ʱ���˺����ܡ�֮һ�ĺ��Ź���������ｨ�����ü����������
���к�����װ�̽�������Ӣ�����ˡ��Ϸ�������һ����ִ���(sign)���Ա߸���
��һ������(duilian) �����ǶԺ���һ�����������ۡ�
LONG
    );
    set("no_kill",  "yangzhou");
    set("detail", ([
        "sign"  : YEL@LONG

              ��  ʿ  ��  ˫
            
LONG
        NOR,
        "duilian"   : @LONG
        
            ��              ��
            ��              ��
            ��              һ
            ��              ֪
            ��              ��
        
LONG
    , ]));        
        
    set("exits", ([
        "north"      : __DIR__"yanxing_jie",
    ]));
    set("objects", ([
        __DIR__"npc/youke"  :   random(4),
    ]));
    setup();
}

    