 //XXDER
inherit ROOM;
void create()
{
        set("short", "ˮ��");
        set("long", @LONG
ˮ���䣬��Ϻ��Ȼ���е��������������ȥ����ס��˫�ȵ�ˮ��������
�����������������ˡ�ˮ���壬���Ŵ�ˮ��͸�����Ĺ��ߣ��㿴������һ��
ˮ�ݵ�����¶��һ��ĥ�̴�С��ʯͷ��ʯͷ�������ǰ�ɫ��ɳ�ӡ�
LONG
        ); 
   set("exits", ([ /* sizeof() == 4 */
       "up" : __DIR__"northpond",
   ])); 
   set("item_desc", ([
      "stone" : "��׵�ʯͷ���˹���ĥ���ĺۼ��������泤����ˮ�ݡ� \n",
      "ʯͷ" : "��׵�ʯͷ���˹���ĥ���ĺۼ��������泤����ˮ�ݡ� \n",
   ]) );
        set("coor/x",190);
        set("coor/y",2000);
        set("coor/z",-20);
   setup();
        
} 
void init()
{
   add_action("do_push", "push");
} 
int do_push(string arg)
{
   object me,room; 
   me = this_player();
   if (!arg || (arg != "stone" && arg != "ʯͷ"))
      return 0;
   if (me->query_temp("marks/opened")) {
      message_vision("\n\n$N������ʯͷ��ȥ��ʯͷ���������ϵ�������һ�߻�����\n",me);
      message_vision("\n\n���е�ˮͻȻ��ʯ��Ŀն�ӿȥ��$N��ͷ��ˮ���������ݺݵ�ײ����ʯͷ�ϣ�\n\n\n",me);
   me->set_temp("marks/guest", 1);
        if(!me->query("m_success/��ƽ"))
        {
                me->set("m_success/��ƽ",1);
                me->add("score",1000); 
        }
   me->unconcious();
   room = find_object("/d/qingping/shenshui/woshi2");
   if(!objectp(room)) room=load_object("/d/qingping/shenshui/woshi2");
   me->move(room);
   }
   else
      message_vision("$Nʹ�������������ʯͷ������˿������\n",me);
   return 1;
}      
