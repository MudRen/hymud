 inherit ROOM;
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
ת������һ��ʯ�ţ�����ڵ��º��ϣ���ˮ���̣��ܺڣ��������˰�
����ɫ�������ź󣬵�·һ��Ϊ�����м�һ���������û��һ˿�ƻ���
���ѱ��������ұ�ͨ�򼸼��ƾɵ�Сʯ�ߣ���ߵ�·�澹Ȼ���ò�ʯ�̳ɣ�
�ڵƹ���ӳ������Ĺ�â��
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"yard1",
                "north" : __DIR__"jailroad1",
                "northwest" : __DIR__"court1",
                "south" : __DIR__"yongdao5",
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
