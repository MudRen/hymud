//Cracked by Roath
// by happ@ys

#include <ansi.h>

inherit NPC;
#include "/d/migong/romnpc2.c"

int send_me();
int work_me();
string expell_me(object me);
string check_book();
int zhua_gui();
string ask_cancel();
string obstacle_sc();

void create()
{
       set_name("阎罗王", ({"yanluo wang","wang", "master", "yanluo"}));
       set("long", "身穿大红蟒袍，头戴黑绸软巾．
面如锅底，须若钢针，这就是阎罗王．\n");
       set("title", "阴间十王之");
        set("class", "youling");
       set("gender", "男性");
       set("age", 50);
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 10);
      

set("inquiry", ([
"name": "哼！连老夫都不认得，想来是活的太久了！\n",
"here": "这便是阎罗地府，到阳间一谈，嘿嘿，没人不怕！\n",
"阳间": "人说阴阳殊途，其实不然，阴阳间有五点相交，来去相通！\n",
"五点": "哈哈，要说知道的人却也不多，那便是年，月，日，时和长安泾水桥！\n",
"刘父": (: obstacle_sc :),
"刘伯钦的父亲": (: obstacle_sc :),

]) );


create_family("阎罗地府", 2, "你好");
setup();
initlvl((500+random(500)),3);
        carry_object("/d/obj/cloth/mangpao")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
string obstacle_sc()
{
        object me = this_player();
        int i;
        if( me->query("obstacle/sc") == "done" )
        return("我不太清楚。\n");
  if (me->query("combat_exp",1) < 1000000)
    return("我不太清楚。\n");            
        if( ! me->query_temp("can_ask") )
          return("我不太清楚。\n");

  i = random(800)+100;
  me->add("obstacle/number",1);
  me->set("obstacle/sc","done");
    me->add("combat_exp",i+7000);
    me->add("potential",i*8);
    me->add("mpgx",10);me->add("expmax",2);
  command("chat "+me->query("name")+"双叉坡灭虎，超度刘父灵魂显功劳！");
message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+me->query("name")+"闯过西行取经[1;37m第二关！\n"NOR,users());
  me->save();
me->move("/d/qujing/shuangcha/sleeproom");

  return("你赢得了"+chinese_number(i+7000)+"点经验"+
               chinese_number(i*8)+"点潜能"+"十点门派贡献 二点成长上限！！\n");

}

