 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "С��");
        set("long", @LONG
һ���ƾɵ�ʯ�ݣ����輫Ϊ��ª�������ﵽ�������Żҳ�����
�������û�����������������ڷ���Ʈҡ����Щ�����ȱ��紵
���ˣ�֩����æ�������»��� 
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"yongdao7",
                
                
        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
void init()
{
        add_action("do_pull", "pull");
} 
int do_pull(string arg)
{
        object room;
        object me;
        me = this_player();
        room = load_object(__DIR__"studyroom");
        message_vision("$Nֻ�����񡱵�һ�������ţ�����һ������������죬�����µ�һ�ѿݲ�ͻȻ������
����¶��һ��������\n",me);
        tell_object(me,"��Խ׹Խ�죮���������ƺ�������һ���ҽУ�����ë���Ȼ��\n");
        me->move(room);
        return 1;
}   
