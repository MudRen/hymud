// Room: /d/jinghai/moon12.c

inherit ROOM;

void create()
{
	set("short", "ʿ��Ӫ��");
	set("long", @LONG
�������߽�������Ϣ�ҵ���������˷�����Ϊˮ�����ְ�ֵ
�أ���������ʲôʱ�����ﶼ������˯����Ϊ�˰�ȫ���������
û��һ����������ǰ����Ϊ��ҵı���������Я����������Ϊ��
�����̷����˶�����Ѫ�¼���
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"moon6",
]));
        set("objects",([
        __DIR__"npc/yong1" : 4,
        __DIR__"npc/duizhang" : 1,
]));


	setup();
	replace_program(ROOM);
}
