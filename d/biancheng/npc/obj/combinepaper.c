 inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name("ţƤ��", ({ "oak latex","latex"}) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "һ��ţƤ�����ƺ���������ճ����Combine��������մɺ�ֽ�š�\n");
        set("value", 200);
        //set("lore",1);
        }
         
}  
 void init()
{
  if(this_player()==environment())
  add_action("do_combine","combine");
} 
int do_combine()
{
int i,red=0,blue=0,yellow=0,green=0;
object jade,me, *inv;
object redi,bluei,yellowi,greeni;
me = this_player();
inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++)
                {
                        if(inv[i]->query("name") == "��ֽƬ���Ͻ�") {yellow = 1; yellowi = inv[i];}
                        if(inv[i]->query("name") == "��ֽƬ���Ͻ�") {green = 1; greeni = inv[i];}
                        if(inv[i]->query("name") == "��ֽƬ���½�") {red = 1; redi = inv[i];}
                        if(inv[i]->query("name") == "��ֽƬ���½�") {blue = 1;  bluei = inv[i];}
                }
if( yellow && blue && red && green )
{
        destruct(redi);
        destruct(yellowi);
        destruct(greeni);
        destruct(bluei);
        jade = new(__DIR__"paper_5");
        jade->move(me);
message_vision(HIW"$N��ϸ����ֽƬƴ��������ճ���ã�һ���ܺ��ͽ�����¶�����ˡ�\n"NOR,this_player());
        if(!this_player()->query_temp("wanma/give_paper"))
        {
                this_player()->set_temp("wanma/give_paper",1);
  
        }
        destruct(this_object()); 
}
else 
message_vision("$N���������ֽƬ��Ū�˼��£�\n",this_player()); 
return 1;
}     