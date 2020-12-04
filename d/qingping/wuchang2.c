 inherit ROOM;
void create()
{
        set("short", "�䳡");
        set("long", @LONG
�����䳡���ˣ���Ȼ���󣬿��Ǹ�����ʩһӦ��ȫ��������÷��׮��
�����ƽ���¼�Ϊע���Ṧ�����̹�������שʯ��ɳ��������Ӳ��������
�������ݣ��ɼ��ڵ���ƽʱ���Ǽ�Ϊ�̿ࡣ
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"wuchang1",
])); 
   set("item_desc", ([
      "÷��׮" : "÷��׮�����������ĳߵ�ľ׮��ɣ���Ϊ��״��÷����������������
��ϰ�Ṧ�ġ�\n",
   ]));
        set("outdoors","qingping");
        set("coor/x",120);
        set("coor/y",2010);
        set("coor/z",0);
        setup();
        
} 
void init()
{
   add_action("do_lian", "lian");
} 
int do_lian(string arg)
{
   object me;
   int  s, amount, da;
  
   if(!arg || arg != "move") return 0;
   me = this_player();
   if( me->is_fighting() )
      return notify_fail("��ս������ϰ����������\n");
   if( me->is_busy() )
      return notify_fail("����һ��������û����ɣ�������ϰ��\n");
   me->start_busy(2);
   s = (int)me->query_skill("move", 1);
   if( random(me->query("kar")) > 9) {
      if(s >= 100) {
         message_vision("\n$N������𣬷ɿ����÷��׮������һȦ��������������������\n", me);
         tell_object(me, "����Ṧ����û��ʲô������\n");
         return 1;
      } 
      if(s >= 50) {
         message_vision("\n$N������𣬷ɿ����÷��׮������һȦ��������������������\n", me);
      } else {
         message_vision("\n$NС�ĵ�������÷��׮����ս�ľ�������һȦ���Ͽ�������������\n", me);
      }
      tell_object(me, "����Ṧ���󳤽���һЩ��\n");
      amount =  (me->query("int") + me->query("cps")) - 20;
      if(amount < 1) amount = 1;
      me->improve_skill("move", amount);
      da = 30*20/(me->query("dur")+me->query("fle"));
      me->receive_damage("qi", da);
   } else {
      message_vision("\n$N���������������÷��׮������һȦ��\n", me);
      message_vision("\n$N��ѽһ����÷��׮�ϵ���������\n", me);
      da = 200*20/(me->query("dur")+me->query("fle"));
      me->receive_damage("qi", da);
   }
   return 1;
}  
