 // XXDER@FY
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���ܸߣ�����������������Ժǽֻ������һ���һ�㣬������������
��������ա������ܶ��ǻ���ï�ܵ�֦Ҷ���㿴����������������������
�����������ؿ���ǰԺ�����䳡�����д�����һ�С�
LONG
        ); 
   set("item_desc", ([
   ]) ); 
   set("objects", ([
      __DIR__"obj/nest": 1,

   ]) ); 
   set("outdoors", "qingping");
        set("coor/x",170);
        set("coor/y",2000);
        set("coor/z",20);
   setup();
} 
void init()
{
   add_action("do_search", "search");
   add_action("do_jump", "jump");
   add_action("do_look", "look");
} 
int do_look(string arg)
{
        if(arg != "nest") return 0;
        if(this_player()->query_temp("marks/foundnest", )) return 0;
        write("��Ҫ��ʲ�᣿\n");
        return 1;
}
int do_jump(string arg)
{
   object me, room; 
   me = this_player();
   if(!arg || arg != "down") return 0;
   message_vision("$N�����ϰ��������ƮƮ���䵽��Ժǽ�ϡ�\n\n", me);
   room = find_object(__DIR__"wall"); 
   if(!objectp(room)) room=load_object(__DIR__"wall");
      me->move(room);
      message("vision",me->name()+"��ƮƮ���䵽��Ժǽ�ϡ�\n", environment(me), me); 
   return 1;
} 
int do_search(string arg)
{
   object  me;
  
   me = this_player();
   if (!arg || arg != "tree" && arg != "��") return 0;
   tell_object(me, "����ϸ�Ĳ鿴�����ڣ���һ����֦�Ϸ���һ�����ѡ�\n"); 
   me->set_temp("marks/foundnest", 1);
   return 1;
} 
void reset()
{
   object *inv;
   object item1, item2, nest;
   ::reset(); 
   nest = present("nest", this_object());
   inv = all_inventory(nest);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/egg");
      item1->move(nest);
      item2 = new(__DIR__"obj/key");
      item2->move(nest);
   }
}     
