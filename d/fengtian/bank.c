// bank  Ǯׯ

#include <ansi.h>

inherit BANK;

void create()
{
        set("short", "����¡Ǯׯʢ���ֵ�");
        set("long", @LONG
���ǳ�������¡Ǯׯ��ʢ���ֺţ�һ���ţ��Ϳ���ǽ���д�
����(sign)����̨���С���������Ц��ӭ�˹��������������
����ʢ������Զ·��
LONG
);
        set("item_desc", ([ /* sizeof() == 2 */
        "sign" :  "����¡ǮׯĿǰ�ṩ�ķ����У�
huan            �һ�Ǯ��
cunqian         ��Ǯ
quqian          ȡǮ
chazhang        ����
zhuan           ת��
",
]));
        set("no_beg", 1);

        set("objects",([
        	__DIR__"npc/banker" :1,        
        ]));

	set("exits", ([
                "north" : __DIR__"wy3",
]) );
        setup();
}
