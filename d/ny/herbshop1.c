// Room: /d/snow/herbshop1.c

inherit ROOM;

void create()
{
	set("short", "ҩ������");
	set("long", @LONG
����һ��������������ң��ӵ��Ϻ��Ļҳ����ó������������
�˳��룬�����ߵĵ��Ϸ���һ�����ͣ�����һ����������ǽ�ϣ���֪��
��������ʲ���ˣ������ǽ(wall)���ú�ɼľ���ģ�����������Ļ���
ǽ�������Ե���Щ��Ѱ����
LONG
	);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
