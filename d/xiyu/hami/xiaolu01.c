// xiaolu01   ����С·
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "С·");
    set( "long", @LONG
һ����ʯС·����ͨ��һ������С�������Զ�ĵط�������˵�ƽ����
������һɨ��Į�Ļ�ɳ���������ܵ������һƬ��䣬��ľ�����дУ�ʮ��ïʢ
�����Ǻ�����֦��Ҷï��ɫ��Ũ�ء�
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "west" : "/d/xiyu/gebi",
    "east" : __DIR__"xiaolu02",
]) );
    set( "outdoors", "����" );
    setup();
}

