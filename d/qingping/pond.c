 //XXDER
inherit ROOM;
void create()
{
   set("short", "����");
   set("long", @LONG
��԰��һСС�ĳ�����һ�����羫�µ�С���ź���ڳ����ϡ���ˮ���̣�
�����м���ʢ����˯�����ۺ죬��ף���ƣ������ű��̵�Ҷ�ӣ�Ư����С����
�ϣ�ɷ������ϲ����һ�ô�����������ߣ���˿���Ʈ�衣����̫��ʯɢ��ط�
�ڳ����ߡ�
LONG
        );
   set("exits", ([ /* sizeof() == 4 */
      "eastup" : __DIR__"bridge",
      "west" : __DIR__"garden",
      "northeast" : __DIR__"northpond",
      "southeast" : __DIR__"southpond",
   ]));
   
   set("item_desc", ([
      "̫��ʯ": "���������̫��ʯ��ɢ��ط��ڳ����ߣ�ʯͷ��һ���ֱ����������£������裩��\n",
      "stone": "���������̫��ʯ��ɢ��ط��ڳ����ߣ�ʯͷ��һ���ֱ����������£������裩��\n",
      "����": "�����ڲ�Զ���ĳ����ߣ������������ڳ����ϡ�\n",
      "tree": "�����ڲ�Զ���ĳ����ߣ������������ڳ����ϡ�\n",
      "˯��": "�뿪��˯����˯��֮�е����ˣ�Ư���ڱ��̵ĳ����ϡ�\n",
      "flower": "�뿪��˯����˯��֮�е����ˣ�Ư���ڱ��̵ĳ����ϡ�\n",
   ]) );
   set("coor/x",180);
        set("coor/y",2000);
        set("coor/z",0);
        setup();
   set("outdoors", "qingping");
} 
void init()
{
   add_action("do_push", "push");
} 
int do_push(string arg)
{
   object me, qiuyin, obj ;
  
   me = this_player();
   obj = this_object();
   if(obj->query("marks/moved")) return notify_fail("ʯͷ�ƺ������ƹ����Ѿ��ɶ��ˡ�\n");
   if (!arg || arg != "stone" && arg != "ʯͷ") 
      return notify_fail("��Ҫ��ʲô ? \n");
   message_vision("$N����������̫��ʯ��ʯ�ߵ����ɶ��ˣ�¶�����������ֵ���򾡣\n", me);
   qiuyin = new(__DIR__"obj/qiuyin");
   qiuyin->move(obj);
   qiuyin = new(__DIR__"obj/qiuyin");
   qiuyin->move(obj);
   obj->set("marks/moved", 1); 
   return 1; 
} 
void reset(){
        ::reset();
        delete("marks/moved");
}      
