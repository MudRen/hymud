 inherit ITEM;
#include <ansi.h> 
void create()
{
    set_name(HIM"��ˮ��"NOR , ({ "purple crystal","crystal"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long", "һ��ɢ���������Ϲ��ˮ��ʯ��\n");
        set("value", 1000);
        set("lore",1);
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
                        if(inv[i]->query("name") == HIY"��ˮ��"NOR) {yellow = 1; yellowi = inv[i];}
                        if(inv[i]->query("name") == HIG"��ˮ��"NOR) {green = 1; greeni = inv[i];}
                        if(inv[i]->query("name") == HIR"��ˮ��"NOR) {red = 1; redi = inv[i];}
                        if(inv[i]->query("name") == HIB"��ˮ��"NOR) {blue = 1;  bluei = inv[i];}
                }
if( yellow && blue && red && green )
{
        destruct(redi);
        destruct(yellowi);
        destruct(greeni);
        destruct(bluei);
        jade = new(__DIR__"stone_0");
        jade->move(me);
message_vision(HIY"$N��������ˮ��ʯ��Ȼ�ۼ���һ�𣬷ų���Ŀ�Ĺ⻪��������\n"NOR,this_player());
        if(!this_player()->query("m_success/ˮ��"))
        {
                this_player()->set("m_success/ˮ��",1);
                this_player()->add("score",200); 
        }
        destruct(this_object()); 
}
else 
message_vision("$N������ļ���ˮ��ʯ��Ū�˼��£�\n",this_player()); 
return 1;
}     
