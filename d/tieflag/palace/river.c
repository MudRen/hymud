 inherit ROOM;
void create()
{
        set("short", "Ϫ��");
        set("long", @LONG
�ļ���СϪ�����������Ϫ���ļӿ������ƽ�Ȱ�����������Ϫ��
��һ��һ�˶�ߵ�«έ�����м��괹�������������ǵ���˿������Ϫ���ϣ�
΢��������ƽ����Ϫ���ϻ���ȦȦ��㣬����ˮ�е������ͣ��Ծ��ˮ
�档��ֻ��ë������ҰѼ��ˮ���ϵ�����ȥ����ʱ�ذ�ͷ̽��ˮ��Ѱ����
�ǵ�ʳ����м�ֻ�ڰ�����Ϣ��
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"grass",
  "west" : __DIR__"naibridge",
  "east" : __DIR__"smalllake",
]));
        set("objects", ([
        __DIR__"npc/duck" : 2,
                        ]) ); 
        set("outdoors","fengyun");
        set("coor/x",170);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",-30);
        set("coor/z",20);
        set("coor/x",170);
        set("coor/y",-30);
        set("coor/z",20);
        setup();
} 
void init()
{
        add_action("do_pick", "pick");
} 
int do_pick(string arg)
{
        object  me, lu; 
        if( arg != "luwei" && arg != "«έ") 
                return notify_fail("ʲô��\n");
        me = this_player();
        if(me->query_temp("marks/luwei"))
                return notify_fail("«έ�Ѿ�����ժû�ˡ�\n");
        lu = new(__DIR__"obj/luwei");
        lu->move(me);
        me->set_temp("marks/luwei", 1);
        message_vision("\n$Nժ��һ��«έ���ڻ��\n", me);
        return 1;
}    
