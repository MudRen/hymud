// bank.c
// by dicky

#include <ansi.h>
inherit BANK;

void create()
{
	set("short", "����Ǯׯ");
        set("long", @LONG
����һ�Һ�С��Ǯׯ�����ڵش���ƫƧ����ɽһ����������
�ⲻ�Ǻܺá���˵������ϰ�����Ҳ��һλ�����ˣ���֪ʲôԭ
����������������������Ψһ��Ǯׯ��һ���ţ��Ϳ���
ǽ���д�����(sign)��Ǯׯ�ϰ��ͷ�����Լ�����Ŀ������̧ͷ
�ۿ��������Ǻ����ˣ��������Ѿ�����֪����
LONG
        );

        set("item_desc", ([ /* sizeof() == 2 */
	"sign" :  "����ǮׯĿǰ�ṩ�ķ����У�
huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan		ת��
",
]));
        set("no_beg", 1);

        set("objects",([
        	__DIR__"npc/banker" :1,        
        ]));
	set("exits", ([
                "south"            : __DIR__"shilu2", ]) );
        setup();
}

