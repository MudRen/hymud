 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ã�ޱ߼ʵĺ�ˮ���������κεĴ�ֻ��·�أ��㱻���ޱ��޼ʵĺ�ˮ
��Χ�ţ����Ų��˶��𸡣���ɬ�ĺ�ˮ��ʱ�ع�����Ŀ��У��㲻�ɵظе�����
������С����֪���ж����������ᡣ
LONG
        );
   set("objects", ([
        __DIR__"npc/snake" : 2
   ]) );    
        set("coor/x",1200);
        set("coor/y",-300);
        set("coor/z",-70);
   setup();
} 
void init()
{
   add_action("do_swim", "swim");
} 
int do_swim(string arg)
{
   object me, room;
   int kar, k;
  
   me = this_player();
   if( me->is_fighting() )
      return notify_fail("����ս���У�\n");
   if( me->is_busy() )
      return notify_fail("����һ��������û����ɡ�\n");
   me->start_busy(2);
   kar = (int)me->query_kar();
   message_vision("\n$N������ǰ��ȥ!\n", me);
   if(random(200) < kar) {
      tell_object(me, "ԶԶ�����ƺ�������һƬ½�أ����þ����е��������Ƕ���ȥ��\n");
      message_vision("$N����ʪ���ܵ������˰���!\n\n", me);
/*      if(random(50) < kar) {
         room = find_object("/d/tieflag/rock0");
         if(!objectp(room)) room = load_object("/d/tieflag/rock0");
         me->move(room);
      } else {*/
      room = find_object("/d/tieflag/seaside");
      if(!objectp(room)) room = load_object("/d/tieflag/seaside");
      me->move(room);
      message("vision", me->name()+"ʪ���ܵشӺ�������������\n", environment(me), me);
      return 1;
   } 
   room = find_object(__DIR__"ocean2");
   if(!objectp(room)) room = load_object(__DIR__"ocean2");
   me->move(room);
   return 1;
}       
