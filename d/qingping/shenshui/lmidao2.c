 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
string stone();
void create()
{
        set("short", "ɽ���ص�");
        set("long", @LONG
�ص�������ͻȻ������γ���һ���޴��ʯ�ң����ڳ����˸���ǧ��
�ٹֵ�����ʯ���ڹ��ߵ���ҫ����˸�����˵�ɫ�ʣ����û�й�������Ѵ���
���Ƴ�ȥ��ʯ��һ����һ���޴�İ�ʯ����һ����Ȼ��������
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"lmidao1",
  "north" : __DIR__"lmidao3",
  "northeast" : __DIR__"lmidao4",
]));
        set("item_desc", ([
                "stone" : (: stone :),
                "��ʯ" : (: stone :),
        ]) );
        set("marks/finished", 0);
        set("coor/x",100);
        set("coor/y",12070);
        set("coor/z",0);
        setup();
} 
void init(){
   add_action("do_write", "write");
} 
string stone(){
        object me;
        me = this_player();
        if(query("marks/finished")){
                tell_object(me, "һ�����ʮ��ƽ���İ�ʯ������ƽ����һ����ֽ������д��Щ�֣�\n\n"); 
                tell_object(me, "               ¥�ⴹ��ǧ���ƣ�\n");
                tell_object(me, "               ��ϵ�ഺ����ס����ȥ��\n");
                tell_object(me, "               ���Է�ǰƮ�������洺�ҿ���δ���\n\n");
                tell_object(me, "               ����ɽ���Ŷ��\n");
                tell_object(me, "               �������飬ĪҲ���˿ࡣ\n");
           tell_object(me, "               �Ѿ��ʹ�������ƻ�ȴ�������ꡣ\n\n");
                tell_object(me, "ֽ�߰����ֳɵı�ī��\n");
        } else {
                tell_object(me, "һ�����ʮ��ƽ���İ�ʯ������ƽ����һ����ֽ������д��Щ�֣�\n\n"); 
                tell_object(me, "               ¥�ⴹ��ǧ���ƣ�\n");
                tell_object(me, "               ��ϵ�ഺ����ס����ȥ��\n");
                tell_object(me, "               ���Է�ǰƮ�������洺�ҿ���δ���\n\n");
                tell_object(me, "               ����ɽ���Ŷ��\n");
                tell_object(me, "               �������飬ĪҲ���˿ࡣ\n");
                tell_object(me, "               �Ѿ��͡�������ƻ�ȴ�������ꡣ\n\n");
                tell_object(me, "�����ƺ����������֣�ֽ�߰����ֳɵı�ī�� \n");
        }
        return "";
}  
int do_write(string arg){
        object  me, room;
   
        me = this_player();
        if(query("marks/finished")){
      return 0;
        } else {
      if(!arg || (arg != "xu chun chun" && arg != "������")) {
         return 0;
      }
      tell_object(me, "����һ����������ڿո������˼����֣��ְѱʷ�����ȥ��\n");
      message("vision", me->name()+"��һ�������Ӱ�ʯ�����д�˼����֣��ְѱʷ��˻�ȥ��\n",environment(me), me); 
      set("marks/finished",1);
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
        ::reset();
        if(query("marks/finished") == 365){
           set("marks/finished", 0);
        } else if(query("marks/finished") == 0) {
                return;
        } else {
                add("marks/finished", 1);
        }
}       
