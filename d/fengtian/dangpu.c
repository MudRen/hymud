// Room: /d/fengtian/dangpu.c

inherit HOCKSHOP;

void create()
{
	set("short", "����");
	set("long", @LONG
����һ���������֣�ʵ������Է��ַ��Ƕĳ���ģ��Ա�
�ĵ���һ������䵱�̵�Ȼ��Ϊ�����÷����ģ����ź��û��
������˵�𲻻𣡹�̨����һ��ľ��(sign)��
LONG
);

set("item_desc", ([
                "sign": @TEXT
���̽��׵ķ���:
[ value | gujia ]     : ����
[ pawn | dang ]       : �䵱
sell                  : ��
[ redeem | shu ]      : ���
list                  : �б�
[ buy | mai ]         : ��
TEXT
]) );

	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"ll1",
]));

	set("objects",([
	__DIR__"npc/dang_boss" : 1,
]));

	setup();
}
