 //XXDER
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ǳ������϶ˣ�վ���������������Ŀ���С�ŵ�ȫò��С�Ų�֪����
ʲôʯͷ���� ��ͨ������覣���ӳ�ڱ��̵�ˮ�У�����˯������������ʯ��
���ߵ�С�����������ѵ�С·��������һ��������ͼ����ǽ�ߴ��£�����Ž�
���������޵Ļ��䣬�Ž��Ի�����һ��СС����齡�
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
   "east" : __DIR__"southpond1",
   "northwest" : __DIR__"pond",
   ])); 
   set("objects", ([
      __DIR__"obj/bamboobed" : 1,
      __DIR__"obj/ground" : 1,
      __DIR__"npc/baoyu": 1,
   ]) ); 
   set("coor/x",190);
        set("coor/y",1990);
        set("coor/z",0);
        setup();
        
   set("outdoors", "qingping");
}
void init()
{
        add_action("do_look","look");
}
int do_look(string arg)
{
        if(arg != "ground") return 0;
        if(!this_player()->query_temp("marks/bajiao"))
        {
        write("��Ҫ��ʲ�᣿\n");
        return 1;
        }
   else return 0;
}
void reset()
{
   object *inv;
   object item1, ob;
   ::reset(); 
   ob = present("bamboo bed", this_object());
   inv = all_inventory(ob);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/pillow");
      item1->move(ob);
   }
   ob = present("ground", this_object());
   inv = all_inventory(ob);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/qiuyin");
      item1->move(ob);
   } 
}     
