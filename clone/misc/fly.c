// more work needed to use this object to make poison
#include <ansi.h>
inherit ITEM;


void init()
{
        add_action("do_eat2", "mygift");
        add_action("do_eat", "ci");
        add_action("do_eat", "he");
        add_action("do_sleep", "xiuxi");
        add_action("do_xx", "xiuxing");
          add_action ("do_fly","chen");
}

void create()
{
	set_name(YEL"���ֱ���"NOR, ({"newbie beg", "beg"}));
        set("unit", "ֻ");
	set("long", "�����濴��ȥ����Զ�Բ���ĸ����������ֳ��ֺȲ���Ϣ(he,ci,xiuxi)��");
set("long", YEL"����ר�ã������濴��ȥ����Զ�Բ���ĸ�����
����㲻֪������������ʲô��������mygift �鿴��ϵͳ��ѡ��һ���ʺ����������ʾ�㡣
������ֳ��ֺȲ���Ϣ����ѳ˳�,����������(he,ci,xiuxi,chen,xiuxing)��
*@*���Դ����(chen)�����µط���*@*
���� ����(tam)        ����(dl)            Ȫ��(qz)  ����
���� ����(shl)        ��ɽ(hs)            ����(lj)  ����
���� �䵱(wd)         ����(mj)            ����(gc)  ����
���� ����(xx)         ѩɽ(xs)            ��ü(em)  ����
���� ȫ��(quz)        ����ɽ(bt)          ��Ĺ(gm)  ����
���� ����(sz)         ����ׯ(gyz)         ����(xy)  ����
���� ����(ca)         �ɶ�(cd)            ����(laz) ����
���� ����(jz)         ʢ��(yj)            ���(wg)  ����
���� ����(km)         ����(hz)            ����(lz)  ����
���� �󳵳�վ(dache)  �������(majiu) ���ݵ���(dp)  ����
���� �Ŵ�(job1)  ĥҩ(job2)   ��ľ(job3) ��Ϸ(job4) ����
���� ����(job5)  �ͻ�(job6)   Ѳ��(job7) ��ɫ(job8) ����
���� �Թ�(job9)  ��ս(job10)                        ����\n"NOR   
);
	set("no_get",1);
	set("no_drop",1);
		set("no_get", 1);
		set("no_put", 1);
		set("no_drop", 1);
             set("value", 0);
             set("material", "steel");
             set("no_drop", "�������������뿪�㡣\n");
        setup();
}

int do_eat2()
{
int exp;
object me = this_player();


if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");

tell_object(me,YEL "������ľ�����"+chinese_number(me->query("combat_exp",1))+"��\n" NOR);
exp=(int)me->query("combat_exp",1);
if (exp<=80000)
tell_object(me,YEL "�����ʺ������������������"+HIR"chen job1\n"NOR+HIR"ask lao about job\n"+HIR"��ذ���help nbjob\n"NOR);

if (exp>80000 && exp<=120000)
tell_object(me,YEL "�����ʺ������������������ڶ��׶Σ�"+HIR"chen job10\n"NOR+HIR"ask bei chou about job\n"+HIR"��ذ���help nbjob\n"NOR);

if (exp>120000 && exp<=180000)
tell_object(me,YEL "�����ʺ����������ĥҩ����"+HIR"chen job2\n"NOR+HIR"ask ping about job\n"+HIR"��ذ���help moyao\n"NOR);

if (exp>=180000 && exp<=300000)
tell_object(me,YEL "�����ʺ����������Ѳ������"+HIR"chen job7\n"NOR+HIR"ask wang about job\n"+HIR"��ذ���help xunchen\n"NOR);

if (exp>80000 && exp<=500000)
tell_object(me,YEL "�����ʺ���������Ƿ�ľ����"+HIR"chen job3\n"NOR+HIR"ask songque about job\n"+HIR"��ذ���help kanshu\n"NOR);

if (exp>=500000 && exp<=1000000)
tell_object(me,YEL "�����ʺ���������ǳ�Ϸ����"+HIR"chen job4\n"NOR+HIR"ask guan about job\n"+HIR"��ذ���help changxi\n"NOR);

if (exp>=180000 && exp<=1500000)
tell_object(me,YEL "�����ʺ���������Ǵ�������"+HIR"chen job5\n"NOR+HIR"south ��ɱ�������ý���\n"+HIR"��ذ���help dalie\n"NOR);

if (exp>=1500000 && exp<=2500000)
tell_object(me,YEL "�����ʺ���������ǲɻ�����"+HIR"chen job8\n"NOR+HIR"ask tian about job\n"+HIR"��ذ���help tianjob\n"NOR);

if (exp>80000 && exp<=2500000)
tell_object(me,YEL "������������ɣ���������������"+HIR"�ҵ����ɵ�������\n"NOR+HIR"����job��duilian ������Ա\n"+HIR"��ذ���help geren\n"NOR);

if (exp>1500000)
tell_object(me,YEL "���Ѿ���һ�������ˣ����ܼ�����Ҫ���������:\n"+HIR"��������:help taskjobs\n"NOR+HIR"��������help geren \n"+HIR"��������help aboutquest\n"NOR);

if (exp>=300000 )
tell_object(me,YEL "���������ȥ�Թ�̽���ˣ�"+HIR"chen job9\n"NOR+"��ذ���help migong\n"NOR);

if (exp>=300000 )
tell_object(me,YEL "���������ȥ��ս�����ˣ�"+HIR"chen job10\n"+HIR"ask bei chou about challenge\n"NOR+"��ذ���help boss ��������-��ս����\n"NOR);

if (exp>2500000)
tell_object(me,YEL "�Ѿ��������ɴ��������ˡ��������ɣ�����ƾ��Ծ��\n"NOR);


me->start_busy(1);
return 1;
}

int do_eat(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
if (!wizardp(me) && me->query("age") > 55)
return notify_fail("ֻ�����ֲ��ܳԸ���!\n");
if (!wizardp(me) &&me->query("str") > 40)
return notify_fail("ֻ�����ֲ��ܳԸ���!\n");
if (!wizardp(me) &&me->query("dex") > 40)
return notify_fail("ֻ�����ֲ��ܳԸ���!\n");

if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");
if ((int)me->query("combat_exp") > 6500000 )
return notify_fail("ֻ�����ֲ��ܳԸ���!\n");

if (me->query("food")*1.5 > me->max_food_capacity()
&& me->query("water")*1.5 > me->max_water_capacity())
return notify_fail("�����ڲ�����!\n");

message_vision(YEL "$N�ó�������Դ����һ��!!\n" NOR,me);
me->set("food",me->max_food_capacity());me->set("water",me->max_water_capacity());
if (me->query("qi") < 50 )
	me->add("qi",30);
if (me->query("jing") < 50 )
	me->add("jing",30);


me->start_busy(3);
}
int do_sleep(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
if (!wizardp(me) &&me->query("age") > 55)
return notify_fail("ֻ�����ֲ�����!\n");
if (!wizardp(me) &&me->query("str") > 40)
return notify_fail("ֻ�����ֲ�����!\n");
if (!wizardp(me) &&me->query("dex") > 40)
return notify_fail("ֻ�����ֲ�����!\n");

if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");
if ((int)me->query("combat_exp") > 6500000 )
return notify_fail("ֻ�����ֲ�����!\n");

if (me->query("qi") > me->query("max_qi")
&& me->query("jing") > me->query("max_jing")
)
return notify_fail("�����ڲ�����!\n");
message_vision(YEL "$N�ó����ֱ������ڵ�����Ϣһ��!!\n" NOR,me);
if (me->query("qi") < me->query("eff_qi"))
me->add("qi",me->query("eff_qi")/2);
if (me->query("jing") < me->query("eff_jing"))
me->add("jing",me->query("eff_jing")/2);


if (me->query("eff_qi") < me->query("max_qi"))
me->add("eff_qi",me->query("max_qi")/2);
if (me->query("eff_jing") < me->query("max_jing"))
me->add("eff_jing",me->query("max_jing")/2);
me->set_temp("isnbbg",1);
me->start_busy(3);
return notify_fail("����Ϣ��һ��!\n");
}

  int do_fly(string arg)
{

          string pla;
          object me = this_player();
if( me->query("jing") < 30 )
               return notify_fail("�㾫�񲻹���ʢ��û����������\n");
if( me->query_temp("pending/team"))
               return notify_fail("�����ͱ�������أ�\n");				

if (!wizardp(me) &&me->query("age") > 55)
return notify_fail("ֻ�����ֲ�����!\n");
if (!wizardp(me) &&me->query("str") > 40)
return notify_fail("ֻ�����ֲ�����!\n");
if (!wizardp(me) &&me->query("dex") > 40)
return notify_fail("ֻ�����ֲ�����!\n");

//if( !environment(me)->query("outdoors") ) 
//          return notify_fail(HIY"\n�������������\n"NOR);


//if( environment(me)->query("chatroom") && environment(me)->query("pingan") )
// return notify_fail(HIY"\n��������в�������\n"NOR);

/*


if( !environment(me)->query("no_fight") && me->query("combat_exp") > 900000)
{
  message_vision("ֻ���ڰ�ȫ��������ҵ���!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("str") > 31)
{
  message_vision("ֻ���ڰ�ȫ��������ҵ���!!!\n"
                 ,me);
      	return 1;
}

if( !environment(me)->query("no_fight") && me->query("zhuanshen"))
{
  message_vision("ֻ���ڰ�ȫ��������ҵ���!!!\n"
                 ,me);
      	return 1;
}
*/

if ( me->query_temp("in_guard")   || me->query_temp("player_working") || me->query_temp("shouwei"))
return notify_fail("������������!\n");

if (!wizardp(me) && me->query("age") > 55 && !wizardp(me))
{
  message_vision("ֻ��С�ڵ���55�꣬�����������!!!\n"
                 ,me);
      	return 1;
}
    if (me->is_fighting()) 
        return notify_fail("���������������!\n");
    if (me->is_busy()) 
        return notify_fail("������������!\n");

          if (!arg)
              return notify_fail("����ȥ���\n");
          if( !wizardp(me) && me->is_fighting()  ) 
          return notify_fail("��ôΣ�գ��ǻ���ʱ��ȥ����?\n");

          if (me->query_temp("pigging_seat"))
                return notify_fail("���뿪�����������ж���\n");
          if( environment(me)->query("light_up"))
               return notify_fail("�ĳ��ﲻ������!!\n");


          else {
          message_vision(HIY
"$N���˸���򣬲���ʾ�����е����ֳ���Ʊ�����ǣ��������\n"+
"$N�����������һ������ඡ���ֻ������ʻ�����ɱ���ȥ������\n\n"NOR, me);
}
          if(arg=="gc") pla = "/d/city/guangchang";
     else if(arg=="xx") pla = "/d/xingxiu/xxh1";
     else if(arg=="mj") pla = "/d/mingjiao/shanmen";
     else if(arg=="em") pla = "/d/emei/qingyinge";
     else if(arg=="shl") pla = "/d/shaolin/guangchang1";
     else if(arg=="lj") pla = "/d/lingjiu/damen";
     else if(arg=="dl") pla = "/d/dali/center";
     else if(arg=="xs") pla = "/d/xueshan/shanmen";
     else if(arg=="wd") pla = "/d/wudang/guangchang";
     else if(arg=="hs") pla = "/d/huashan/zhenyue";
     else if(arg=="tam") pla = "/d/beijing/tian_anm";
     else if(arg=="quz") pla = "/d/quanzhen/damen";
     else if(arg=="bt") pla = "/d/baituo/dating";
     else if(arg=="qz") pla = "/d/quanzhou/zhongxin";
     else if(arg=="gm") pla = "/d/gumu/mumen";
     else if(arg=="sz") pla = "/d/suzhou/canlangting";
     else if(arg=="gyz") pla = "/d/guiyun/taihu";
     else if(arg=="xy") pla = "/d/xiangyang/guangchang";
     else if(arg=="ca") pla = "/d/changan/ca";
     else if(arg=="cd") pla = "/d/chengdu/guangchang";
     else if(arg=="laz") pla = "/d/lanzhou/guangchang";
     else if(arg=="jz") pla = "/d/jingzhou/guangchang";
     else if(arg=="km") pla = "/d/kunming/jinrilou";
     else if(arg=="yj") pla = "/d/yanjing/street";               
     else if(arg=="wg") pla = "/d/wuguan/guanmen";
     else if(arg=="hz") pla = "/d/hangzhou/kedian";
     else if(arg=="lz") pla = "/d/lingzhou/center";
     else if(arg=="dache") pla = "/d/city/kedian";
     else if(arg=="majiu") pla = "/d/city/majiu";
     else if(arg=="wm") pla = "/d/city/wumiao";
     else if(arg=="dp") pla = "/d/city/dangpu2";
     else if(arg=="job1") pla = "/d/welcome/welcome";
     else if(arg=="job2") pla = "/d/city/yaopu";
     else if(arg=="job3") pla = "/quest/famu/shulin2";
     else if(arg=="job4") pla = "/quest/changxi/xiyuan";
     else if(arg=="job5") pla = "/d/welcome/fight3";
     else if(arg=="job6") pla = "/quest/songhuo/huowo";
     else if(arg=="job7") pla = "/d/pingan/bingyin";
     else if(arg=="job8") pla = "/d/henshan/huiyan";
     else if(arg=="job9") pla = "/d/migong/migong3";
     else if(arg=="job10") pla = "/d/city/kedian";
     
               else {
               message_vision(HIR
"�����˰��죬�ŷ���$NҪȥ�ĵط�����û�Ǹ�վ��\n���$N���������������ˤ�ñ������ף�\n"NOR, me);
}
     if (me->move(pla)) {
       message_vision(HIC"\n���ˣ������ȵ�ͣ�����£�$N�����������Գ�����˻��֡�\n"NOR,me);
if( me->query("age") <= 18 )
           me->add("jing",-10);
 else   me->add("jing",-30);
}
     return 1;
}

int do_xx(string arg)
{
object me = this_player();
	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");
if (!wizardp(me) && me->query("age") > 55)
return notify_fail("ֻ�����ֲ�����!\n");
if (!wizardp(me) && me->query("str") > 40)
return notify_fail("ֻ�����ֲ�����!\n");
if (!wizardp(me) && me->query("dex") > 40)
return notify_fail("ֻ�����ֲ�����!\n");

if (me->is_busy())
return notify_fail("������æ��\n");
if (me->is_fighting())
return notify_fail("�����ڴ�\n");
if ((int)me->query("combat_exp") > 6500000 )
return notify_fail("ֻ�����ֲ�����!\n");

if ( (int)me->query("jing") < 30 || (int)me->query("qi") < 30 )
return notify_fail("�������̫���ˣ�û�취���С�!\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");



if (me->query_temp("working") >=1)
{
	write(""+me->query("name")+"���羲ˮ�����붨����\n");
}
else
{
	message_vision(YEL "$N�ó����ֱ������ڵ��Ͽ�ʼ��������!!\n" NOR,me);
	write(""+me->query("name")+"�������񣬿�ʼ�������С�\n");
}
	

	me->add_temp("working",1);
if (me->query("qi") < me->query("max_qi"))
me->add("qi",me->query("max_qi")/5);
if (me->query("jing") < me->query("max_jing"))
me->add("jing",me->query("max_jing")/5);
me->start_busy(6);

if (me->query_temp("working") >=6)
	call_out("work_end", 1, me);

return 1;
}


int work_end(object me)
{
	object ob1;
	int add_exp,add_pot,add_score;
	me->delete_temp("working");
	write("������������,����һЩ��������\n");
	me->receive_damage("jing",me->query("jing")/8);
	me->receive_damage("qi",me->query("qi")/8);

		add_exp=2+random(3);
		add_pot=1+random(2);
if ((int)me->query("combat_exp",1) < 1200000 && !me->query("zhuanshen") && !me->query("zhuanbest")  && !me->query("guard/flag"))
{
		add_exp=3+random(4);
		add_pot=2+random(2);

}

		add_score=1+random(1);
		me->add("combat_exp",add_exp);
		me->add("potential",add_pot);
		//me->add("score",add_score);
		ob1 = new("/clone/money/silver");
		ob1->set_amount(add_score);
		ob1->move(me);	
		tell_object(me,HIW"��õ���:"
			+ chinese_number(add_exp) + "��ʵս���飬"
			+ chinese_number(add_pot) + "��Ǳ�ܡ�\n"NOR);		
				
	if ( me->query_temp("working") ) me->delete_temp("working");
	return 1;
}