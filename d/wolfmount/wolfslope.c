 inherit ROOM;
void create()
{
        set("short", "Ұ����"); 
        set("long", @LONG
ɽ�ƽ�������ǰ�µ���һ���������ڡ�ɽ�Ҹ߸����ϣ���Լ����Ӱ���������
���µ��Ĳ��������������������������ط��Ͽ�������������ʯ��û�С����׵�
ɽ�����Ӳݴ�������Լ�ɿ����и����߿�խ��ɽ����
LONG);
        set("type","mountain");
        set("item_desc", ([
                "ɽ��": "һ��ֻ�����߿�խ�Ķ��ڣ����Զ���������ȥ��������죩��\n",
                "cave": "һ��ֻ�����߿�խ�Ķ��ڣ����Զ���������ȥ��������죩��\n",
        ]) );
        set("coor/x",-690);
        set("coor/y",-700);
        set("coor/z",50);
        set("objects", ([
        __DIR__"obj/grass" : 1,
                        ]) );
       set("outdoors", "wolfmount");
        set("exits",([
                "southup":__DIR__"gully",
                "northeast":__DIR__"wolfhill2",
        ]) );
        setup();
}
void reset()
{
        object *inv;
        object con, item;
        ::reset();
        con = present("grass", this_object());
        inv = all_inventory(con);
        if( !sizeof(inv)) {
        item = new(__DIR__"obj/yeguo");
        item->move(con);
        }
} 
void init()
{
        add_action("do_crawl", "crawl");
} 
int do_crawl(string arg)
{
        object  me; 
        if(!arg) 
        {
                write("��Ҫ�������\n");
                return 1;
        }
        
        if( arg == "up" || arg == "ɽ��" )
        {
                me = this_player();
                message_vision("$Nץ��ɽ���ϵ��Ӳݣ�����������ɽ����\n", me);
                me->start_busy(2);
                call_out("fliping",2,me);
                me->stop_busy();
                return 1;
        }
        else
        {
                write("�㲻������"+arg+"��\n");
                return 1;
        }
} 
int fliping(object me)
{
        object room;
        if( !me->is_ghost()) 
        {
                message_vision("$N��������ɽ���\n", me);
                room = find_object(__DIR__"wolfcave");
                if(!objectp(room)) room= load_object(__DIR__"wolfcave");
                me->move(room);       
        }
        return 1;
} 
