// zjb /2002/3/15/
inherit ROOM;
int do_piao(string arg);  
int do_zheng(string arg);
void on_wang();
void create()
{
        set("short", "����");
        set("long", @LONG 
����һ������,���������Զ,�����ѳ����ฯ�����,
��Ȼ���Ժ����׵���(zheng)��, ���������Ǹ��޵׶�, 
���ܶ��Ǹֱ�!
LONG
        );
        set("exits", ([
                              ]));
set("no_fight",1);
        set("item_desc", ([ 
          "����" : "���Ŵ����ƺ��������ػζ�(huang)!\n",         
        ]));

        set("no_clean_up", 0);
        setup();
}
void init()
{
                
   add_action("do_piao", "huang"); 
 add_action("do_zheng", "zheng");
}
int do_piao(string arg)
{
        object me; 
               me = this_player();
      if( !arg || arg=="" ) return notify_fail("��Ҫ�ζ�ʲô����!\n");
     if( arg=="wang" ) {
       write("��ʹ���ζ�����,��������Ʈ����\n");
      this_player()->set_temp("piaowang", 1);
                         return 1;
        }
        else {
            write("����ζ�ʲô����?!\n");
            return 1;
        }
       }  
int do_zheng(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("��û����ʲô��!\n");
  if( arg=="wang" ) {
        if (me->query_temp("piaowang") ) {
       write("��ʹ������,���Ӵ�����ѡ�\n");
       write("������������������ƣ�������֮�����ɵ����ְ�������ȥ�� �ɹ������ڸְ����԰�͹�ұڵĶ��ڴ���\n");
                        this_player()->delete_temp("piaowang"); 
    me->move(__DIR__"qiangbi");
            return 1;
        }
}
        else {
            write("��û����ʲô��!\n");
     return 1;
        }
}



