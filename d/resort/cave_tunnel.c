 inherit ROOM;
void create()
{
        set("short", "��ɽ��");
        set("long", @LONG
��Բ�����ɽ���������˹�����ĺۼ����丵�ϸ��˳�Ŷ�
��������������������ˮ�������ƽ������ߣ����Ŵӳ��ڴ�͸��
����⣬�㷢�ֽ��µ�ʯ����Ȼ�Ǻ������ɵġ�
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"secret_road",
  "west" : __DIR__"another_sky",
]));
        set("coor/x",-1210);
        set("coor/y",30);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}    
