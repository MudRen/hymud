 inherit ROOM;
void create()
{
        set("short", "������ɽ·"); 
        set("long", @LONG
һ���ӿ����ݵ�ʯ��ɽ·�����Թ�ʯ��ᾡ������ɽ����ʱ��ʱ���������Ǻ�
����·���������Լ������װ׹ǡ�͸��ɽ����Լ��ɿ������Ϸ���Զ����һ��
������
LONG);
        set("type","road");
        set("exits",([
                "northdown":__DIR__"ehugang",
                "southup":__DIR__"shanlu4",
                "southwest":__DIR__"undertower",
        ]) ); 
        set("outdoors", "bawang");
    set("coor/x",200);
    set("coor/y",-210);
    set("coor/z",60); 
        setup();
        replace_program(ROOM);
}
