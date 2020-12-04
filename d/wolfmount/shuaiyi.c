 inherit ROOM;
void create()
{
        set("short", "������"); 
        set("long", @LONG
���Ǽ����ɿ���ʮ���ɳ��Ĵ����������߽�����ʱ��ʵ���벻���Ǽ������
������ô��һ���ط������������һ��ıڽ����ѩ��Ω��һ����ŷ�����ͼ��
��������һ��ȴ�����š����Ͻ����������������ƺ�����һ�����������
LONG); 
        set("type","indoors");
       set("indoors", "wolfmount");
        set("NONPC",1);
        set("exits",([
                "north":__DIR__"grasscabin",
        ]) );
        set("item_desc", ([
                "zhulian": "��������ƺ������ƿ���������\n",
                "����": "��������ƺ������ƿ���������\n",
        ]) );
        set("coor/x",-640);
        set("coor/y",-820);
        set("coor/z",100);
        set("objects",([
                __DIR__"npc/lanlan":1,
                __DIR__"npc/zhuyun":1,                  
                __DIR__"obj/shuaiyitu" : 1,
        ]) ); 
        setup();
} 
void init()
{
        add_action("do_open", "open");
} 
void close_path()
{
        if( !query("exits/south") ) 
                return;
        message("vision","������������������ס�˰��š�\n",this_object() );
        delete("exits/south");
} 
int do_open(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) 
                return 0; 
        if( arg=="zhulian" || arg =="����" || arg=="curtain" ) 
        {
                write("���ƿ�������");
                if( (int) me->query("neili") >= 80 )
                {
                        write("�ƿ��˺������ϵ��š�\n");
                        if( !query("exits/south") ) 
                        {
                                set("exits/south", __DIR__"backroom");
                                call_out("close_path", 15);
                        }
                        return 1;       
                }
                else
                        write("���������ƺ�����ţ���û���ƿ���\n");
                return 1;
        }
                write("��Ҫ�ƿ�ʲô��\n");
                return 1;
} 
int valid_leave(object me, string dir)
{
        object ob;
        int i;
        if( dir == "south" && ob=present("zhu yun", this_object()))
        {
                if ( (string)me->query("class") != "wolfmount" )
                {
                        message_vision("$N��$n�ȵ�����̫ү�����κ��˴��������\n", ob,me);
                        ob->kill_ob(me);
                        return notify_fail("���Ƶ�ס�����ȥ·��\n");
                }
        }
        return 1;
} 
void reset(){
        object item;
        ::reset();
      
        if(!present("shuaiyi picture", this_object())){
                item = new(__DIR__"obj/shuaiyitu");
                if(objectp(item)){
                        item->move(this_object());
                }
        }
        return;
}         
