 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
���ܴ����ܵ�Ⱥɽ�����￴���Եú�С��ˮ������䣬����ػ�������
��������ܣ����ϵİ��ƻ����ر任����״���㼸��������ʱ��Ĵ��ڣ�Ȼ��
����ĺ�ˮȴ���㳶�ص���ʵ�У����ǲ�Ҫ���������̫�á�
LONG
        );
   set("objects", ([
      __DIR__"npc/frog" : 2,
   ]) );
        set("outdoors","shenshui");
        set("coor/x",200);
        set("coor/y",12300);
        set("coor/z",10);
        setup();
} 
void init()
{
   add_action("do_swim", "swim");
   remove_call_out("do_cold");
   call_out("do_cold",5, this_object()); 
} 
int do_cold(object ob) 
{
   object *inv;
   int  i, da; 
   inv = all_inventory(this_object());
   if(sizeof(inv) == 0) return 1;
   for(i=0;i<sizeof(inv);i++) {
      if(userp(inv[i])) {
         message_vision("\n$N���������һ����ս!\n", inv[i]);
         tell_object(inv[i], "���ǿ���뿪����ɡ�\n");
         da = 50000 / (inv[i]->query("max_neili")+1);
         if(da>100) da = 50+random(50);
         if(da<10) da = 10+random(30);
         inv[i]->receive_damage("qi", da); 
      }
   }
   call_out("do_cold", 5+random(10), this_object());
} 
int do_swim()
{
   object me, room;
   int kar, k;
  
   me = this_player();
   if( me->is_busy() )
      return notify_fail("����һ��������û����ɡ�\n");
   me->start_busy(2);
   kar = (int)me->query("kar");
   k = kar - 15; if(k<1) k = 1;
   message_vision("\n$N�����������ȥ!", me);
   if(random(kar) < k) {
      message_vision("$N����ʪ���ܵ������˰���!\n\n", me);
      room = find_object(__DIR__"baishui");
      if(!objectp(room)) room = load_object(__DIR__"baishui");
      me->move(room);
      message("vision", me->name()+"ʪ���ܵشӺ�������������\n", environment(me), me);
   } else {
      message_vision("һ�ɰ����ְ�$N���˻���!\n", me);
   }
   return 1;
}        
