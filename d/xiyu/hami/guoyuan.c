// guoyuan.c   ��԰
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "��԰");
    set( "long", @LONG
һƬ��԰�����������ȵ������²������⣬�������ֲ��ȷ���û����ԡ�һ
�ۿ���ȥ���������Ĺ��ܹϣ����ѡ��������ȵȣ��в���ˮ�����ڼ��ϵģ�����
�ϵģ�������ô�����ˡ���԰�������һ����԰�ˡ�
LONG );
    set( "exits", ([ /* sizeof() == 2 */
    "west" : __DIR__"shiban03",
]) );
    set( "outdoors", "����" );
    set( "objects", ([
    __DIR__"npc/mmaiti" : 1,
]) );
    setup();
}

