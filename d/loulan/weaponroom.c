 inherit ROOM;
void create()
{
        set("short", "�ٱ���");
        set("long", @LONG
�����־�����£������������º��ܣ�����ٱ��Թ�ɳ��֮�ã����ٱ��Ȿ
�ǹ�¥���ĳ�ʷ����ʮ���Ӵ��ΰ���ֱ����������Ϊ�����⣬�������б��ϡ���
�ϡ����ϡ����С����䣬�����������У�ʽ�����࣬ʮ֮�˾Ŷ���������������
����Ѱ����̽����磬�е�����߲����еĺ�����ˣ����������ۻ����ҡ� 
LONG
        ); 
        set("exits", ([ 
                "east" : __DIR__"southstrt",
        ]));
        set("objects", ([
                __DIR__"obj/sword" : 1,
                __DIR__"obj/blade" : 1,
                __DIR__"obj/axe" : 1,
                __DIR__"obj/hammer" : 1,
                __DIR__"obj/spear" : 1,
                __DIR__"obj/whip" : 1,
                __DIR__"obj/staff" : 1,
       ]) );
        set("indoors", "loulan"); 
        set("coor/x",-1010);
        set("coor/y",180);
        set("coor/z",-100);
        setup();
}  
