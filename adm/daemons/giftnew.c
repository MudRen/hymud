#include <ansi.h>
string *typew=({
"sword",
"blade",
"hammer",
"whip",
"club",
"staff",
"throwing",
"dagger",
"axe",
});
string *typea=({
"hands",
"cloth",
"armor",
"boots",
"head",
"neck",
"surcoat",
"shield",
"waist",
"wrists",
});

int give_jl(object me)
{
object env,envt,ob,corpse,obj;
mapping exit;
int maxpot,i2;
     object who;
      object *team;
	  int i=0,count=0,minexp,maxexp,a,exp,pot,neili;
int ckiller,rn;
      string where;
string file;
string *roomlines;
string location;
int mi,yi,yai,lv,lb,money;
    string *ob_list = ({
                "/clone/family/jinkuai",
                "/clone/family/jintiao",
                "/clone/family/xiaoyuanbao",
                "/clone/family/dayuanbao",
                "/clone/family/jinding",
        });
who =me;
seteuid(geteuid(this_object()));
if (!me) return 1;

        if(me->query("gender")=="����")
    tell_object(me,"���Ȳ������ڵ���ʬ��Ѱ����һ�£����ã�\n");
        else
    tell_object(me,"��С�������ڵ���ʬ��Ѱ����һ�£����ã�\n");

if (!environment(me))
      {
tell_object(me,"�����˰���ʲô��û���ҵ���\n");
if (!me->is_busy()) me->start_busy(3);
return 1;
      }	 
env=environment(me);
    if(environment(me)->query("short")!=BLU"ɽ��"NOR
       && environment(me)->query("short")!=WHT"����ʯ��"NOR
       && environment(me)->query("short")!=YEL"�Ҷ�"NOR
       && environment(me)->query("short")!=RED"���Ҷ�"NOR
       && environment(me)->query("short")!=CYN"ʯ��"NOR
       && environment(me)->query("short")!=RED"��������ͷ"NOR
       && !environment(me)->query("magicroom")
       && !environment(me)->query("maze")  )
      {
tell_object(me,"�����˰���ʲô��û���ҵ���\n");
if (!me->is_busy()) me->start_busy(3);
return 1;
      }	 

if (random(3)==0)
{
if (random(20)==0)
{
ob = new(ob_list[random(sizeof(ob_list))]);
         ob->move(env);
        tell_object(who, HIM "���ҵ���һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
return 1;
}

ob = new("/clone/money/silver");
if (random(3)==0) ob = new("/clone/money/gold");
if (random(3)==1) ob = new("/clone/money/coin");
        money=8+random(18);
        tell_object(who, HIY "���ҵ���" + money +
                        ob->query("base_unit") + ob->name() +
                        HIY "��\n" NOR);

        ob->set_amount(money);
        ob->move(env);
        return 1;
}

//1/12�õ�ҩ��
if (random(18)==1)
	{
file = read_file("/clone/medicine/ycgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           ob = new(location);
if (ob)
{
           ob->move(env);
        tell_object(who, HIM "���ҵ���һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}
return 1;
}


//1/60�õ���ָ
if (random(70) == 1 && !env->query("alrd"))
{
	i2=10;
if (random(3)==0) i2=20;
if (random(6)==0) i2=30;
if (random(9)==0) i2=40;
if (random(18)==0) i2=50;
if (random(32)==0) i2=60;	
             corpse=new("/clone/gem/ring"+random(i2));
             message_vision("$N�õ�һ���������Ľ�ָ��\n",me);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���һö"+corpse->query("name")+HIM"!"NOR"��\n", users());
             corpse->move(env);
environment(this_object())->set("alrd",1);
        
return 1;
}


//1/30�õ�����װ��
if (random(35)==0  && !env->query("alrd"))
{
	file = read_file("/clone/medicine/wgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           ob = new(location);
if (ob)
{
           ob->move(env);
        tell_object(who, HIM "���ҵ���һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

}
    
return 1;
}

//����װ���õ�
//1/60����
yai=random(100);
 if ((int)who->query("combat_exp",1) > 12000000 && random(2))
{
yai=yai+random(381);
}
else 
 if ((int)who->query("combat_exp",1) > 8500000 && random(2))
{
yai=yai+random(300);
}
else 
 if ((int)who->query("combat_exp",1) > 6500000 && random(2))
{
yai=yai+random(200);
}
else
 if ((int)who->query("combat_exp",1) > 5500000 && random(2))
{
yai=yai+random(100);
}
else if ((int)who->query("combat_exp",1) > 3500000 && random(2))
{
yai=yai+random(50);
}


if (yai>480) yai=479;
if (yai> 400 && random(3)==1) yai=random(400);
if (yai> 300 && random(3)==2) yai=random(300);
if (yai> 200 && random(3)==3) yai=random(200);
if (random(70)==1 )
{
ob = new("/p/item/ritemw/W"+typew[random(9)]+yai);
                ob->set("no_drop",0);
                ob->set("no_get",0);
           ob->move(env);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

        tell_object(who, HIM "���ҵ���һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
return 1;
}
else if (random(70)==2 )
{
ob = new("/p/item/ritema/A"+typea[random(10)]+yai);
                ob->set("no_drop",0);
                ob->set("no_get",0);
           ob->move(env);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

        tell_object(who, HIM "���ҵ���һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
     
return 1;
}


//����װ��
if (1==1)
	{
file = read_file("/clone/medicine/yb");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           ob = new(location);
if (ob)
{
           ob->move(env);
        tell_object(who, HIM "���ҵ���һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}
return 1;
}


}
   