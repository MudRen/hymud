#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�汦�����");
        set("long", @LONG 
����һ��Բ�ε�ʯ�ң���������Բ�ε�ʯ�������а���
ʯ�Σ������һ��ͼ�Ĳ�ï�����꾡�ı����ͼ������ʾ��
�����������¹���Ĺ�ϵ������Բ�εĵ��������ĵ���ͨ
��ľ�ţ��ֱ�ͨ���ĸ��ر��ң������б��л�ʯ�����ں�ֽ
ú���Թ���ȼƽ���ֲ��������ұ��ϵİ�յǽ�ơ�
LONG );
	set("objects", ([
		__DIR__"obj/corpse" : 3,
	]));

               set("exits", ([
                "north"  : __DIR__"baokun",
                "west"   : __DIR__"baokuw",          
                "east"   :  __DIR__"baokue",
                "south"  : __DIR__"baokus",
                                
        ]));
        set("item_desc", ([ 
          "ʯ��" : MAG"�㷢�ֱ������������ص�����ڷֱ����Ŀ�֮��
������һ��ֱ�����һ��С�𴦡���\n"NOR, 
  
 ]));


  set("no_clean_up", 1);
        setup();
}


void init()
{
    object *obj;
  object me = this_player();
   obj=children(__DIR__"obj/ssl");
delete_temp("ssl");
   if (sizeof(obj)>4)  set_temp("ssl",1);
        add_action("do_zhuan", "zhuan");
        add_action("do_ba", "ba"); 
        add_action("do_pai", "pai");
        add_action("do_pick", "pick");
}

int do_pai(string arg)
{
        object me;
        me = this_player();
      if( !arg || arg=="" ) return notify_fail("��Ҫס����ʲô����!\n");
            if( arg=="ʯ��" ) {
write(HIB"������ȥʱ�о��������Ƶ����������ǿ��Ի�����ӡ�\n"
HIB"Ī����������??\n"NOR);
             this_player()->set_temp("paizhuo", 1);
             return 1;
       }
}

int do_ba(string arg)
{
        object me;
        me = this_player();
      if(! me->query_temp("paizhuo")) return 0;
      if( !arg || arg=="" ) return notify_fail("��Ҫ��ʲô����!\n");
            if( arg=="����" ) {
 write(HIB"��˫��ץ�����أ����ϰ�������Ӧ���������磬����һ�����졣
\n"NOR); 
         write(HIC"�����ƺ�����������ת��������ת�ıߺ���? \n"NOR);
             this_player()->set_temp("bazhuo", 1);
             this_player()->delete_temp("paizhuo");
             return 1;
       }
}

int do_zhuan(string arg)
{
        object me; 
    object room;
    string dir;
             me = this_player();
 if (!me->query_temp("bazhuo")) 
return 0;
      if( !arg || arg=="" ) return notify_fail("��Ҫתʲô����!\n");
      if( sscanf(arg, "%s", dir)==1 ) {

    if( dir=="left" ) {
   message_vision(HIC"$N����������ת��һת��\n"NOR, this_player()); 
 call_out("on_kai", 1);
               this_player()->delete_temp("bazhuo");
return 1;
}
 else if( dir=="right" ) {
                     
            message_vision(HIC"$N����������ת��һת��\n"NOR, this_player()); 
     message_vision(HIC"ͻȻ$N�Ľŵ��³���һ������$N������ȥ��\n"NOR, this_player());

     this_player()->move("/d/lumaji/pomiao");
     this_player()->unconcious();
     this_player()->delete_temp("bazhuo");
        return 1;
        }
        else {
            write("����ת���ĸ�����?\n");
            return 1;
        }
}
} 

int do_pick(string arg)
{
   object ssl, hezi, me=this_player();

        if( !arg || arg=="" ) return 0;
if (!me->query_temp("pick_shen")) 
return 0;
if (query_temp("picktime")>time())
return notify_fail("�ող���������ʥ����,�㻹���ٵȼ����ӿ�����!\n");

        if( arg=="Сͭ��" )
                             {  
if(query_temp("ssl")){ 
   message_vision("$N��ȥ��ͭ�н�������Ѿ���������\n", this_player());
     this_player()->move("/d/lumaji/pomiao");
     return 1;
 }
                                message_vision(
HIY"$N��С�ռ����ó���һ��Сͭ��!\n"NOR, this_player());
           ssl = new(__DIR__"obj/ssl");
                 hezi = new(__DIR__"obj/hezi");
  ssl->set("zhuren",""+me->query("id")+"");
                      ssl->move(hezi);   
                      hezi->move(me);   
set_temp("ssl",1);
set_temp("picktime",time()+1800);
me->delete_temp("pick_shen");
// message("channel:chat", HBWHT HIC"������"+me->query("name")+"��������﷢�������ص�Сͭ����!\n"NOR,users()); 

return 1;
                }
       return 0;
}

void on_kai(object room)
{
message_vision(HIG"����һ���ذ�ͻȻ���³�ȥ���ֳ�����խС�Ŀռ�!\n
����ռ����ƺ��и�Сͭ��,���ƺ�������(pick)����!\n"NOR, this_player());
this_player()->set_temp("pick_shen",1);
}

