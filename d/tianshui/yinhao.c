// /d/tianshui/yinhao.c

inherit BANK;
void create()
{
        set("short", "��ˮǮׯ");
        set("long", @LONG
����һ�������Թ�ƽ�������Ƶ�Ǯׯ��Ǯׯ���ϰ廹�Ǹ���
���й����˵Ķ����ˣ�����Կ���Ǯׯ�������ⶼ��ɨ��ǬǬ��
����һ�����ֵ����������ڹ�̨���棬��̨�Ϲ���һ��������
����(paizi)��
LONG
);
	set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"eroad1",
]));

        set("item_desc", ([
                "paizi": @TEXT
������Ǯׯ��Ŀǰ�����ṩ�ķ����У�
convert         �һ�Ǯ�ҡ�
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����     
TEXT
        ]) );
        set("objects", ([
                __DIR__"npc/banker": 1 ]) );
        setup();
}