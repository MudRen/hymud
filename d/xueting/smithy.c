// Room: /d/snow/smithy.c
inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
������һ��������ӣ���¯��ð���Ļ�⽫ǽ��ӳ��ͨ�죬��
�ӵĽ���������˸�ʽ���������Ʒ��δ���Ʒ�����ǳ�ͷ��������
���ӡ������ȵȳ������������������������õ��������죬һ����
��[paizi]����ǽ�ϡ�
LONG
        );
	set("item_desc",([
		"paizi" : "�߼��չ����������ף�������(pei)Կ�ף�����(xiuli)������\n",
]));
	set("exits", ([
	"west"          : __DIR__"guangchang_s",
	]) );

	set("objects",([
		__DIR__"npc/smith" :1,
]));
        setup();
	replace_program(ROOM);
}
