 inherit ITEM;
void create()
{
   set_name("���ʯ", ({ "stone" , "white stone", "ʯͷ" }) );
   set_weight(500);
   set_max_encumbrance(8000);
   set("no_get", 1);
   set("no_shown", 1); 
   if( clonep() )
      set_default_object(__FILE__);
   else {
      set("prep", "on");
      set("unit", "��");
      set("long", "һ�����ʮ��ƽ���İ�ʯ������ƽ����һ����ֽ������д��Щ�֣� 
      ¥�ⴹ��ǧ���ƣ�
      ��ϵ�ഺ����ס����ȥ��
      ���Է�ǰƮ�������洺�ҿ���δ��� 
      ����ɽ���Ŷ��
      �������飬ĪҲ���˿ࡣ
      �Ѿ��͡�������ƻ�ȴ�������ꡣ 
�����ƺ����������֣�ֽ�߰����ֳɵı�ī��
\n");
   }
    
} 
void init()
{
   add_action("do_write", "write");
} 
int do_write(string arg)
{
   object obj, me, room;
   
   obj = this_object();
   me = this_player();
   if(obj->query_temp("marks/finished"))
      return 0;
   else {
      if(!arg || (arg != "xu chun chun" && arg != "������")) {
         return 0;
      }
      tell_object(me, "����һ����������ڿո������˼����֣��ְѱʷ�����ȥ��\n");
      message("vision", me->name()+"��һ�������Ӱ�ʯ�����д�˼����֣��ְѱʷ��˻�ȥ��\n",environment(me), me);
      set("long", "һ�����ʮ��ƽ���İ�ʯ������ƽ����һ����ֽ������д��Щ�֣� 
      ¥�ⴹ��ǧ���ƣ�
      ��ϵ�ഺ����ס����ȥ��
      ���Է�ǰƮ�������洺�ҿ���δ��� 
      ����ɽ���Ŷ��
      �������飬ĪҲ���˿ࡣ
      �Ѿ��ʹ�������ƻ�ȴ�������ꡣ 
ֽ�߰����ֳɵı�ī��
\n");
      obj->set_temp("marks/finished",1);
      me->set_temp("marks/guest", 1);
      tell_object(me, "��ֻ���ú������ƺ���ʲô��������һ�¡�\n");
      me->unconcious();
      message("vision", "��ֻ������ǰһ��������һ����Ӱ�ӹ���"+ me->name() +"��ʧȥ����Ӱ��\n", environment(me),me);
      room = find_object("/d/qingping/shenshui/woshi2");
      if(!objectp(room)) room=load_object("/d/qingping/shenshui/woshi2");
      me->move(room);
   }
   return 1;
} 
void reset(){ 
      set("long", "һ�����ʮ��ƽ���İ�ʯ������ƽ����һ����ֽ������д��Щ�֣� 
      ¥�ⴹ��ǧ���ƣ�
      ��ϵ�ഺ����ס����ȥ��
      ���Է�ǰƮ�������洺�ҿ���δ��� 
      ����ɽ���Ŷ��
      �������飬ĪҲ���˿ࡣ
      �Ѿ��͡�������ƻ�ȴ�������ꡣ 
�����ƺ����������֣�ֽ�߰����ֳɵı�ī��
\n");
        delete("marks/finished");       
}    
