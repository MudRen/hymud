// �����°�

#include <ansi.h>
inherit ITEM;
int do_open(string arg);

string *box_object=({
"/clone/magic/obj/book11",
"/clone/magic/obj/book12",
"/clone/magic/obj/book13",
"/clone/magic/obj/book21",
"/clone/magic/obj/book22",
"/clone/magic/obj/book23",
"/clone/magic/obj/book31",
"/clone/magic/obj/book32",
"/clone/magic/obj/book33",
"/clone/magic/obj/book41",
"/clone/magic/obj/book42",
"/clone/magic/obj/book43",
"/clone/magic/obj/book62",
"/clone/magic/obj/book63",
"/clone/magic/obj/book61",
"/clone/magic/obj/book52",
"/clone/magic/obj/book53",
"/clone/magic/obj/book51",
"/clone/magic/obj/book11",
"/clone/magic/obj/book12",
"/clone/magic/obj/book13",
"/clone/magic/obj/book21",
"/clone/magic/obj/book22",
"/clone/magic/obj/book23",
"/clone/magic/obj/book31",
"/clone/magic/obj/book32",
"/clone/magic/obj/book33",
"/clone/magic/obj/book41",
"/clone/magic/obj/book42",
"/clone/magic/obj/book43",
"/clone/magic/obj/book62",
"/clone/magic/obj/book63",
"/clone/magic/obj/book61",
"/clone/magic/obj/book52",
"/clone/magic/obj/book53",
"/clone/magic/obj/book51",
"/clone/magic/obj/cloth",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item15",
"/clone/magic/obj/item16",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item25",
"/clone/magic/obj/item26",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item33",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item36",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item15",
"/clone/magic/obj/item16",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item25",
"/clone/magic/obj/item26",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item33",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item36",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/food1",
"/clone/magic/obj/food2",
"/clone/magic/obj/food3",
"/clone/magic/obj/food4",
"/clone/magic/obj/food5",
"/clone/magic/obj/food6",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item11",
"/clone/magic/obj/item12",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item13",
"/clone/magic/obj/item14",
"/clone/magic/obj/item15",
"/clone/magic/obj/item16",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item21",
"/clone/magic/obj/item22",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item23",
"/clone/magic/obj/item24",
"/clone/magic/obj/item25",
"/clone/magic/obj/item26",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item31",
"/clone/magic/obj/item32",
"/clone/magic/obj/item33",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item34",
"/clone/magic/obj/item35",
"/clone/magic/obj/item36",
"/clone/magic/obj/s1",
"/clone/magic/obj/s1",
"/clone/magic/obj/s1",
"/clone/magic/obj/s10",
"/clone/magic/obj/s11",
"/clone/magic/obj/s12",
"/clone/magic/obj/s13",
"/clone/magic/obj/s14",
"/clone/magic/obj/s15",
"/clone/magic/obj/s16",
"/clone/magic/obj/s17",
"/clone/magic/obj/s18",
"/clone/magic/obj/s19",
"/clone/magic/obj/s2",
"/clone/magic/obj/s2",
"/clone/magic/obj/s2",
"/clone/magic/obj/s20",
"/clone/magic/obj/s21",
"/clone/magic/obj/s22",
"/clone/magic/obj/s23",
"/clone/magic/obj/s24",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s9",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s9",
"/clone/magic/obj/sword",
"/clone/magic/obj/w1",
"/clone/magic/obj/w1",
"/clone/magic/obj/w1",
"/clone/magic/obj/w10",
"/clone/magic/obj/w11",
"/clone/magic/obj/w12",
"/clone/magic/obj/w13",
"/clone/magic/obj/w14",
"/clone/magic/obj/w15",
"/clone/magic/obj/w16",
"/clone/magic/obj/w17",
"/clone/magic/obj/w18",
"/clone/magic/obj/w19",
"/clone/magic/obj/w2",
"/clone/magic/obj/w2",
"/clone/magic/obj/w2",
"/clone/magic/obj/w20",
"/clone/magic/obj/w21",
"/clone/magic/obj/w22",
"/clone/magic/obj/w23",
"/clone/magic/obj/w24",
"/clone/magic/obj/w3",
"/clone/magic/obj/w4",
"/clone/magic/obj/w5",
"/clone/magic/obj/w6",
"/clone/magic/obj/w7",
"/clone/magic/obj/w8",
"/clone/magic/obj/w9",
"/clone/magic/obj/w3",
"/clone/magic/obj/w4",
"/clone/magic/obj/w5",
"/clone/magic/obj/w6",
"/clone/magic/obj/w7",
"/clone/magic/obj/w8",
"/clone/magic/obj/w3",
"/clone/magic/obj/w4",
"/clone/magic/obj/w5",
"/clone/magic/obj/w6",
"/clone/magic/obj/w7",
"/clone/magic/obj/w8",
"/clone/magic/obj/water1",
"/clone/magic/obj/water2",
"/clone/magic/obj/water3",
"/clone/magic/obj/water4",
"/clone/magic/obj/s1",
"/clone/magic/obj/s1",
"/clone/magic/obj/s1",
"/clone/magic/obj/s10",
"/clone/magic/obj/s11",
"/clone/magic/obj/s12",
"/clone/magic/obj/s13",
"/clone/magic/obj/s14",
"/clone/magic/obj/s15",
"/clone/magic/obj/s16",
"/clone/magic/obj/s17",
"/clone/magic/obj/s18",
"/clone/magic/obj/s19",
"/clone/magic/obj/s2",
"/clone/magic/obj/s2",
"/clone/magic/obj/s2",
"/clone/magic/obj/s20",
"/clone/magic/obj/s21",
"/clone/magic/obj/s22",
"/clone/magic/obj/s23",
"/clone/magic/obj/s24",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s9",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s3",
"/clone/magic/obj/s4",
"/clone/magic/obj/s5",
"/clone/magic/obj/s6",
"/clone/magic/obj/s7",
"/clone/magic/obj/s8",
"/clone/magic/obj/s9",
"/clone/magic/obj/sword",
});

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


             

void create()
{
	set_name(HIR"��֮����"NOR, ({"bao xiang", "bao", "xiang"}));
        set("no_get",1);
	set("vendetta/authority",1);
	set_weight(100000);
	set_weight(10);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���ú챦ʯ�������ɵ�"+HIG"���䣬"NOR+"�ƺ����Դ�(openbox)��\n");
		set("unit", "��");
		set("value", 0);
	}
}


void init()
{
   add_action("do_open","openbox");
}

   

int do_open(string arg)
{ 
object env,envt;
mapping exit;
object me=this_player(),ob,corpse,obj;
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
	  who =this_player();
	  //me=this_object();

env = environment(me);
	

    if( me->is_busy() )
    return notify_fail("����æ���ء�\n");
    if( me->is_fighting() )
    return notify_fail("����æ���ء�\n");

        if(me->query("gender")=="����")
    tell_object(me,"���Ȳ������ؽ�"+HIG+"��ľ����"NOR+"�򿪣�\n");
        else
    tell_object(me,"��С������ؽ�"+HIY+"��ľ����"NOR+"�򿪣�\n");

    if( me->over_encumbranced() )
    return notify_fail("���ϴ��Ķ���̫���ˣ��ò����ˡ�\n");


//1/3�õ�Ǯ
if (random(3)==0)
{
if (random(10)==0)
{
ob = new(ob_list[random(sizeof(ob_list))]);
         ob->move(who,1);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}

ob = new("/clone/money/silver");
if (random(3)==0) ob = new("/clone/money/gold");
if (random(3)==1) ob = new("/clone/money/coin");
        money=18+random(88);
        if (who->query("combat_exp",1) < 1000000) money=10+random(10);
        if (who->query("combat_exp",1) < 2000000) money=10+random(15);
        if (who->query("combat_exp",1) < 3000000) money=10+random(20);
        if (who->query("combat_exp",1) < 4000000) money=10+random(30);
        tell_object(who, HIY "������" + money +
                        ob->query("base_unit") + ob->name() +
                        HIY "��\n" NOR);

        ob->set_amount(money);
        ob->move(who,1);
destruct(this_object());         
        return 1;
}
//�����ʯ����ɽ��,�ϴ����Ӿ����Ǳ��
if (random(8)==0 || environment(me)->query("short")==CYN"ʯ��"NOR || environment(me)->query("short")==BLU"ɽ��"NOR)
{
exp=random(1000)+100;
pot= exp/2+10;	
neili=random(30)+30;
if(random(6)==0 )
      {
        tell_object(me,HIY"�����﷢��һ����͵�"+HIY"���,��ľ���������"+ exp +"��!!"NOR+"��\n"NOR);
	me->add("combat_exp", exp);
destruct(this_object());   
    return 1;
      }  
      else if(random(7)==1 )
      {
        tell_object(me,HIY"�����﷢��һ����͵�"+HIY"���,���Ǳ��������"+ pot +"!!"NOR+"��\n"NOR);
	me->add("potential",pot);        
destruct(this_object());   
    return 1;
      }  
      else if(random(7)==2 )
      {
        tell_object(me,YEL"�����﷢��һ����͵�"+YEL"���,�������������"+ neili +"��\n"NOR);
	me->add("max_neili",neili);
destruct(this_object());   
    return 1;
      }  
      else if(random(8)==3 )
      {
        tell_object(me,YEL"�����﷢��һ����͵�"+YEL"���,��ľ���������"+ exp +"��,Ǳ��������"+ pot +"��,����������"+ neili +"��!!"NOR+"��\n"NOR);
	me->add("combat_exp", exp);
	me->add("potential",pot);        
	me->add("max_neili",neili);
destruct(this_object());   
    return 1;
      }  

}

//1/12�õ�ҩ��
if (random(12)==1)
	{
file = read_file("/clone/medicine/ycgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           ob = new(location);
if (ob)
{
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
}
destruct(this_object());         
return 1;
}		



//1/10 ׷ɱ
if( !environment(me)->query("no_fight")
&& random(10)==1 && me->query("combat_exp",1)> 8000000)
{
obj=new("/d/migong/obj/npct"); 
maxpot=me->query_temp("maxpot")+10;
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N��Ц��������ı��ｻ����! !\n"NOR, obj);
me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
//destruct(this_object());         
return 1;
}
//1/12 �����˼��
if (random(30)==0  && me->query("combat_exp",1)> 18000000) 	
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		me->set("startroom", "/d/wizard/robot_court");
		obj->test_robot(me);
me->start_busy(10);
destruct(this_object()); 
    return 1;
}	

//1/60�õ���ָ
if (random(60) == 1 && !environment(this_object())->query("alrd"))
{
	i2=10;
if (random(3)==0) i2=20;
if (random(6)==0) i2=30;
if (random(9)==0) i2=40;
if (random(18)==0) i2=50;
if (random(32)==0) i2=60;	
             corpse=new("/clone/gem/ring"+random(i2));


             message_vision("$N�õ�һ���������Ľ�ָ��\n",me);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "���Թ����ҵ���һö"+corpse->query("name")+HIM"!"NOR"��\n", users());
             corpse->move(me);
environment(this_object())->set("alrd",1);
destruct(this_object());         
return 1;
}



//�������Թ��л��

    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR
       || environment(me)->query("short")==RED"��������ͷ"NOR
       || environment(me)->query("magicroom")
       || environment(me)->query("maze")  )
{

//1/30�õ�����װ��
if (random(30)==0 && environment(me)->query("short")!=CYN"ʯ��"NOR  && !environment(this_object())->query("alrd"))
{
	file = read_file("/clone/medicine/wgift");
roomlines = explode(file,"\n");	
location = roomlines[random(sizeof(roomlines))];
           ob = new(location);
if (ob)
{
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

}
destruct(this_object());         
return 1;
}

//�������
mi=1;
if (random(4)==0) mi=2;
if (random(8)==0) mi=3;
if (random(16)==0) mi=4;
if (random(32)==0) mi=5;
if (random(64)==0) mi=6;	
if (random(128)==0) mi=7;
if (random(256)==0) mi=8;
if (random(512)==0) mi=9;
if (random(1024)==0) mi=10;				

yi=1;
if (random(8)==0) yi=2;
if (random(16)==0) yi=3;
if (random(32)==0) yi=4;
if (random(64)==0) yi=5;
if (random(128)==0) yi=6;	

yai=7;
if (random(8)==0) yai=8;
if (random(16)==0) yai=9;
if (random(32)==0) yai=10;
if (random(64)==0) yai=11;
if (random(128)==0) yai=12;	


if ((int)who->query("combat_exp",1) < 10000000)
{
	if (mi> 6) mi=6;
	if (yi> 4) yi=4;
	if (yai> 10) yai=10;
}

if ((int)who->query("combat_exp",1) < 5000000)
{
	if (mi> 5) mi=5;
	if (yi> 3) yi=3;
	if (yai> 9) yai=9;
}


if ((int)who->query("combat_exp",1) < 2000000)
{
	if (mi> 3) mi=3;
	if (yi> 2) yi=2;
	if (yai> 8) yai=8;
}
//��ʯ������� 1/60
if (random(60)==0 && environment(me)->query("short")!=CYN"ʯ��"NOR  && !environment(this_object())->query("alrd"))
{

           ob = new("/p/newweapon/weaponobj/kuangshi"+mi);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());
             //corpse->move(me);

destruct(this_object());         
return 1;
}

else if (random(60)==1 && environment(me)->query("short")!=CYN"ʯ��"NOR  && !environment(this_object())->query("alrd"))
{

           ob = new("/p/newweapon/weaponobj/buliao"+mi);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

destruct(this_object());         
return 1;
}

else if (random(60)==2 && environment(me)->query("short")!=CYN"ʯ��"NOR  && !environment(this_object())->query("alrd"))
{
           ob = new("/p/newweapon/weaponobj/material"+yi);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

destruct(this_object());         
return 1;
}

else if (random(60)==3 && environment(me)->query("short")!=CYN"ʯ��"NOR)
{
           ob = new("/p/newweapon/weaponobj/material"+yai);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
destruct(this_object());         
return 1;
}

else if (random(60)==4 && (int)who->query("combat_exp",1) > 1000000 && environment(me)->query("short")!=CYN"ʯ��"NOR  && !environment(this_object())->query("alrd"))
{
           ob = new("/clone/gem/gem");
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

destruct(this_object());         
return 1;
}
else if ( (random(60)==0 && (int)who->query("combat_exp",1) > 3000000) && environment(me)->query("short")!=CYN"ʯ��"NOR  && !environment(this_object())->query("alrd"))
{
lv=0;
lb=random(28)+1;
if (random(2)==0 && lb <=12 ) lb= 12+random(17);
if (random(3)==0 && lb <=12 ) lb= 12+random(17);


if (random(4)==0) lv=100;
if (random(16)==0) lv=200;
if (random(32)==0) lv=300;
if (random(64)==0) lv=400;
if (random(128)==0) lv=500;	
if (random(256)==0) lv=600;
if (random(512)==0) lv=700;
if (random(1024)==0) lv=800;


if (random(2)==0 && lv >=300 ) lv= 300;
if (random(3)==0 && lv >=400 ) lv= 400;

if ((int)who->query("combat_exp",1) < 5000000)
{
	if (lv> 500) lv=500;
}

if ((int)who->query("combat_exp",1) < 10000000)
{
	if (lv> 600) lv=600;
}

if ((int)who->query("combat_exp",1) < 15000000)
{
	if (lv> 700) lv=700;
}

lb=lb+lv;
           ob = new("/p/newweapon/weaponobj/jade"+lb);
           ob->move(who);
        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

destruct(this_object());         
return 1;
}

//����װ���õ�
yai=random(100);
 if ((int)who->query("combat_exp",1) > 12000000 && random(3))
{
yai=yai+random(381);
}
else 
 if ((int)who->query("combat_exp",1) > 8500000 && random(3))
{
yai=yai+random(300);
}
else 
 if ((int)who->query("combat_exp",1) > 6500000 && random(3))
{
yai=yai+random(200);
}
else
 if ((int)who->query("combat_exp",1) > 5500000 && random(3))
{
yai=yai+random(100);
}
else if ((int)who->query("combat_exp",1) > 3500000 && random(3))
{
yai=yai+random(50);
}


if (yai>480) yai=479;
if (yai> 400 && random(3)==1) yai=random(400);
if (yai> 300 && random(3)==2) yai=random(300);
if (yai> 200 && random(3)==3) yai=random(200);
//1/60����
if (random(60)==1 && (int)who->query("combat_exp",1) > 2500000)
{
ob = new("/p/item/ritemw/W"+typew[random(9)]+yai);
                ob->set("no_drop",0);
                ob->set("no_get",0);
           ob->move(who);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
destruct(this_object());         
return 1;
}
else if (random(60)==2 && (int)who->query("combat_exp",1) > 2500000)
{
ob = new("/p/item/ritema/A"+typea[random(10)]+yai);
                ob->set("no_drop",0);
                ob->set("no_get",0);
           ob->move(who);
message("channel:chat", HIM"������ҥ�ԡ���˵"+me->name() + "�ҵ���"+ob->query("name")+HIM"!"NOR"��\n", users());

        tell_object(who, HIM "������һ" + ob->query("unit") + ob->name() +
                        HIM "��\n" NOR);
destruct(this_object());         
return 1;
}

}


//һ�㴦��
    if(random(200)>180)
      {
        me->add("eff_jing",-50);
        me->add("eff_qi",-100);
        tell_object(me,"�����﷢������"+HIR"����,��������!"NOR+"��\n"NOR);
      }  
      else if(random(200)>180)
      {
        me->add("eff_jing",-50);
        me->add("eff_qi",-100);
        tell_object(me,"�����﷢������"+HIR"����,��������!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("snake_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("wugong_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("wugong_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("zhizhu_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("xiezi_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(200)>198)
      {
        me->apply_condition("chanchu_poison",10);
        me->add("qi",-10);
        tell_object(me,"�����﷢������"+RED"����,�����˶�!"NOR+"��\n"NOR);
      }  
      else if(random(100)>98 )
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,��ľ���������!!"NOR+"��\n"NOR);
	me->add("combat_exp", 1000);
      }  
      else if(random(100)>98 )
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,���Ǳ��������!!"NOR+"��\n"NOR);
	me->add("potential",500);        
      }  
      else if(random(100)>98 )
      {
        tell_object(me,"�����﷢��һ����͵�"+YEL"���,�������������!!"NOR+"��\n"NOR);
	me->add("max_neili",50);
      }  
      else if(random(100)>98 )
      {
        tell_object(me,"�����﷢��һ����͵�"+YEL"���,��ľ���,Ǳ��������������!!"NOR+"��\n"NOR);
	me->add("combat_exp", 1000);
	me->add("potential",500);        
	me->add("max_neili",50);
      }  
      else if(random(160)==0    && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�Ż�����!!"NOR+"��\n"NOR);
        ob=new(__DIR__"zhu7");
        ob->move(me);
        environment(this_object())->set("alrd",1);
      }  
      else if(random(150)==1 && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��������!!"NOR+"��\n"NOR);
        ob=new(__DIR__"zhu1");
        ob->move(me);
      }  
      else if(random(100)==2
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�Ż�����!!"NOR+"��\n"NOR);
        ob=new(__DIR__"baowu/huozhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }  
      else if(random(150)==3 && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��������!!"NOR+"��\n"NOR);
        ob=new(__DIR__"zhu2");
        ob->move(me);
      }  
      else if(random(100)==4 
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��������!!"NOR+"��\n"NOR);
        ob=new(__DIR__"baowu/leizhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }  

      else if(random(150)==5 )
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�Ÿ�����!!"NOR+"��\n"NOR);
        ob=new(__DIR__"zhu3");
        ob->move(me);
      }  
      else if(random(100)==6 
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��������!!"NOR+"��\n"NOR);
        ob=new(__DIR__"baowu/tuzhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }  

      else if(random(150)==7     )
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ������!!"NOR+"��\n"NOR);
        ob=new(__DIR__"zhu4");
        ob->move(me);
      }  
      else if(random(100)==8
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�ŷ�����!!"NOR+"��\n"NOR);
        ob=new(__DIR__"baowu/fengzhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }  

      else if(random(150)==9 && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ����ò��!!"NOR+"��\n"NOR);
        ob=new(__DIR__"zhu6");
        ob->move(me);
      }  

      else if(random(150)==10  && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ�Ÿ�Ե��!!"NOR+"��\n"NOR);
        ob=new(__DIR__"zhu5");
        ob->move(me);
      }  
      else if(random(100)==11 
      && !environment(this_object())->query("alrd"))
      {
        tell_object(me,"�����﷢��һ����͵�"+HIY"���,����һ��ˮ����!!"NOR+"��\n"NOR);
        ob=new(__DIR__"baowu/shuizhu");
        ob->move(me);
environment(this_object())->set("alrd",1);
      }  

      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
        ob->set_amount(random(150));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"����"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
        ob->set_amount(random(150));
        ob->move(me); 
        tell_object(me,"������һЩ"+HIY"����"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/silver");
        ob->set_amount(random(150));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"����"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/coin");
        ob->set_amount(random(1000));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"ͭǮ"NOR+"��\n"NOR);
      }  
      else if(random(100)>95)
      {
        ob=new("/clone/money/coin");
        ob->set_amount(random(1000));
        ob->move(me);
        tell_object(me,"������һЩ"+HIY"ͭǮ"NOR+"��\n"NOR);
      }  
      else
      {
       int rand;
       rand=random(sizeof(box_object));
           ob=new(box_object[rand]);
 if(ob)
{
        ob->move(me);
        ob->move(me);
        tell_object(me,"������"+HIY":"+ob->query("name")+"."NOR+"��\n"NOR);
}
else            tell_object(me,"���ʲôҲû��!"NOR+"��\n"NOR);
      }  

	destruct(this_object());         
        return 1;
}