//�����dream-blade,��ˮ¥֮��skill
//edit by Trf
#include <combat.h>
#include <ansi.h>
inherit SKILL;
//inherit F_FUNCTION;
void seven(object me,object victim,object weapon,int damage);
void lockman(object me,object victim,object weapon,int damage);
void four_kill(object me,object victim,object weapon,int damage);
int five_kill(object me,object victim,object weapon,int damage);
void lovekill(object me,object victim,object weapon,int damage);
void power_slash(object me,object victim, object weapon,int damage);
void heartkill(object me,object victim,object weapon,int damage);
void dream(object me,object victim,object weapon,int damage);
void fast(object me,object victim,object weapon,int damage);
void disenforce(object me, object victim, object weapon, int damage);
void two(object me,object victim,object weapon,int damage);

mapping *action = ({
//1-8�����齣
//1
([ "action" :NOR"                                  "HBRED"==��һ���ľ���=="NOR"\n"NOR+
             HIW"$N�ђ���$w"HIW"���֣�������ˮ������ͳ�������������������������һ���ܳ�������\n"
            +HIW"��һ�����ǹ��꣬Ҳ���Ƕ��ǣ�����һ�ֻ꾡������Ʈ����ת���˵���ٶȣ��׵���㵣���$n"HIW"������"NOR,
               "dodge"  :        1,
               "move"   :        3,
               "damage" :        180,
               "parry"  :          5,
               "force"  :        200,
               "post_action":  (: two :),
               "damage_type":  "���Ž���",
]),
//2
([ "action" :NOR"                                  "HBRED"==��һ��������=="NOR"\n"NOR+
             HIW"$w"HIW"ӭ��������������һ��������â���������¸����˼�����â�����������ÿ�������\n"
            +HIW"һ�ڱƽ��ľ��̣����罣����ļ�Ī��������$n"HIW"����ػ���$n"HIW"���У�ֱ������"NOR,
               "dodge"  :         2,
               "move"   :          0,
               "damage" :        200,
               "parry"  :         10,
               "force"  :        200,
               "post_action":  (: lovekill :),
               "damage_type":  "��Թ����",
]),
//3
([ "action" :NOR"                                  "HBRED"==��һ������Ȼ=="NOR"\n"NOR+
             HIW"$N�ľ������ȣ��ƺ�һ��������$w"HIW"�Ѵ̳�������⣬��һ������Ĺ��Σ�������׼���\n"
            +HIW"ֱ��$n����Ӱ������ĺޣ�ǳǳ���Σ��������µ���\�ۣ�"NOR,
               "dodge"  :        1,
               "move"   :          0,
               "damage" :        180,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: lockman :),

               "damage_type":  "���齣��",
]),
//4
([ "action" :NOR"                                  "HBRED"==��һ���ķ���=="NOR"\n"NOR+
             HIW"$N��һ�����⾳���޷��������ͼ����������ȥ���ݣ��Ȳ��ǿ졢�಻���桢Ҳ���Ǿ�������ֻ��������\n"
            +HIW"����һ��ֻӦ�����У���Ӧ�����޵Ľ�����$n"HIW"��㶵�������ɲ�Ǽ����ᣡ"NOR,
               "dodge"  :         1,
               "move"   :         3,
               "damage" :        200,
               "parry"  :         10,
               "force"  :        200,
               "post_action":  (: four_kill :),

               "damage_type":  "Ī������",
]),
//5
([ "action" :NOR"                                  "HBRED"==��һ���Ĳ���=="NOR"\n"NOR+
             HIW"$NХ����������ӥ���������Ӱ�����������У����ƺ��е����������಻��������â������ҹ�ǰ��\n"
            +HIW"��$n"HIW"��֪��������ܣ�ɲ�Ǽ佦���˵���Ѫ�⣡"NOR,
               "dodge"  :        1,
               "move"   :          0,
               "damage" :        180,
               "parry"  :          0,
               "force"  :        250,

               "post_action":  (: power_slash :),
               "damage_type":  "������",
]),
//6
([ "action" :NOR"                                  "HBRED"==��һ��������=="NOR"\n"NOR+
             HIW"$N���е�$w"HIW"����һ�����������⣬���ľ������������ֵ���һĨ��ɫ��������죬��Ӱ���Σ�\n"
            +HIW"���������������ޱȣ���$n"HIW"���Եֵ��������ķ�â���뼡�ǣ�"NOR,
               "dodge"  :        2,
               "move"   :        2,
               "damage" :        200,
               "parry"  :         2,
               "force"  :        200,

               "post_action":  (: seven :),
               "damage_type":  "��������",
]),
//7
([ "action" :NOR"                                  "HBRED"==��һ���İ���=="NOR"\n"NOR+
             HIW"�������ϵĽ������ͷ·�ͳ�������������ɢ�������ģ���翵Ľ���������Զ�����˵ĺ�����\n"
            +HIW"����������˵һ��˵�����İ���޿��κεİ��ȴ�ִ���˵������������"NOR,
               "dodge"  :        1,
               "move"   :        1,
               "damage" :        200,
               "parry"  :        7,
               "force"  :        500,
"post_action":  (: dream :),
               "damage_type":  "��Թ����",
]),
//8
([ "action" :NOR"                                  "HBRED"==��һ���ļ�į=="NOR"\n"NOR+
             HIW"�����Ľ�����$n"HIW"��������������ᣬ����һ��������һ�����Ͱ�$n"HIW"�ļ��䵼����Ҫ���˵���һ�θ�����\n"
            +HIW"�Ѱ��绻�ϻƻ�ļ�į����$n"HIW"��ʧȥ�Լ��ĸо����������µ�΢����ƽ���£����Ҳ������֣�"NOR,
               "dodge"  :          1,
               "move"   :          1,
               "damage" :        350,
               "parry"  :          1,
               "force"  :        350,
               "post_action":  (: heartkill :),
               "damage_type":  "��Թ����",
]),
//9
([ "action" :NOR"                                  "HBRED"==��һ���Ĳп�=="NOR"\n"NOR+
             HIW"$N�ђ���$w"HIW"���֣�������ˮ������ͳ�������������������������һ���ܳ�������\n"
            +HIW"��һ�����ǹ��꣬Ҳ���Ƕ��ǣ�����һ�ֻ꾡������Ʈ����ת���˵���ٶȣ��׵���㵣���$n"HIW"������"NOR,
               "dodge"  :          1,
               "parry"   :          1,
               "damage" :        350,
               "parry"  :          50,
               "force"  :        350,
               "post_action":  (: fast :),
               "damage_type":  "��Թ����",
]),

//10
([ "action" :NOR"                                  "HBRED"==��һ���ľ���=="NOR"\n"NOR+
             HIW"$N�ľ������ȣ��ƺ�һ��������$w"HIW"�Ѵ̳�������⣬��һ������Ĺ��Σ�������׼���\n"
            +HIW"ֱ��$n����Ӱ������ĺޣ�ǳǳ���Σ��������µ���\�ۣ�"NOR,
               "dodge"  :          1,
               "parry"   :          1,
               "damage" :        350,
               "parry"  :          50,
               "force"  :        350,
               "post_action":  (: disenforce :),
               "damage_type":  "��Թ����",
]),

});


mapping query_action(object me,object weapon)
{
        string actionn;
        int limit;
        int skill_level = me->query_skill("love-sword",1);

if (!userp(me)) return action[random(10)];
        limit= skill_level/50+1;
       if (limit < 2 )
                return action[0];
       else if (limit < 4 )
                return action[random(2)];
       else if (limit < 6 )
                return action[random(3)];
       else if (limit < 7 )
                return action[random(4)];
       else if (limit < 9 )
                return action[random(5)];
       else if (limit < 10 )
                return action[random(6)];
       else if (limit < 11 )
                return action[random(7)];
       else
                return action[random(10)];
}

//two ok
void two(object me,object victim,object weapon,int damage)
{
     int bell,sk,mk,mk1,i;
     
     if (!me || !victim) return;
     bell=me->query("bellicosity",1);
     sk= me->query_skill("love-sword", 1);
if (sk<=50)sk=50;
     mk=(int)me->query("MKS");
     if(mk<8500) {damage = 3*sk;mk1=5;}
     else 
             if(mk<9000) {damage = 3*sk;mk1=4;}
     else 
             if(mk<9500) {damage = 3*sk;mk1=3;}
     else 
             if(mk<10000) {damage = 3*sk;mk1=2;}
     else {damage = 3*sk;mk1=1;}

        if(   me->query_skill_mapped("sword") == "love-sword"  
         && me->query_skill_mapped("force") == "bluesea-force"
         && !me->is_busy()
        &&  random(3)==0 )
         {
                   message_vision(HIW"\n       ����һ��磬����һ��\�̣����þ�������ˮ��ô��Ȼ����������������Ҳ����������������ɱ��\n\n"
                               HIW"                          �������⻪����������ã��߸����ϣ�����Ʈ��\n\n"
                                 HIW"                   $nֻ��������⻪�·�����Լ�ü��䣬�ַ·���������翼�\n\n"
                                 HIW"                   ���ı仯�������ѳ�Խ�����������ļ��ޣ������������޷�����\n\n"NOR,me,victim);
                for(i=0;i<=mk1;i++)
                {
                          victim->receive_damage("qi",damage,me);
                          COMBAT_D->report_status(victim);
                       }
         me->start_busy(1);
         }
}

//lovekill ok
void lovekill(object me,object victim,object weapon,int damage)
{
 int bell,mk,skillb;
 if (!me || !victim) return;
 bell=me->query("bellicosity",1);
 mk=me->query("MKS",1);
 skillb = (int)me->query_skill("love-sword",1);

if( !me->query_temp("lovekill")  && me->query_skill_mapped("force") == "bluesea-force"          && !me->is_busy())
 {
         if( random(3)==0 && mk < 9000 && skillb>150)
           {

        message_vision("

"HIW"                        "BLINK"�� �������������ˣ��������������� ��"NOR"

"HIY"--����Ը���������ڵ�ԸΪ����֦--"NOR"
"HIR"                                       �����ݺᣬ��Ӱٿ�����·�ն�������¾���\n"NOR,me,victim);
             victim->receive_damage("qi",skillb,me);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--�������ڳ���ʱ�������ڳ���ĺĺ--"NOR"
"HIR"                                       ƽ��һ����������㯣��·���������³���\n"NOR,me,victim);
             victim->receive_damage("qi",skillb,me);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--���ĵؽ�����ʱ��ֻ����˼�޾���--"NOR"
"HIR"                                       ������ƣ����ö�Ŀ���·���������»���\n"NOR,me,victim);
             victim->receive_damage("qi",skillb,me);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--�´������ղ��ڣ�Ϊ����������--"NOR"
"HIR"                                       ������˸������Ʈ�����·𶯳�����������\n"NOR,me,victim);
             victim->receive_damage("qi",skillb,me);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--���鲻�ƶ���࣮һ�绹��ǧ����\--"NOR"
"HIR"                                       ����¶����ҷ����𣬷·�ó�����������\n"NOR,me,victim);
             victim->receive_damage("qi",skillb,me);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--����ɴ���׷�䣮ֻ�ǵ�ʱ���Ȼ--"NOR"
"HIR"                                       ����һ�����������ǣ��·��ճ������¹⻪\n"NOR,me,victim);
             victim->receive_damage("qi",2*skillb,me);
             victim->start_busy(random(2));
             COMBAT_D->report_status(victim);
           me->start_busy(1);
           }
  }
  me->delete_temp("lovekill");
}
//busy����,���й���֮����
void lockman(object me,object victim,object weapon,int damage)
{
        int mk,mecor,victimcor;
        int sk = me->query_skill("love-sword",1);
if (!me || !victim) return;
        mk=me->query("MKS",1);
        mecor=me->query("cor",1 )+me->query("cps", 1 )
              +me->query("combat_exp", 1)/100000;
        victimcor= victim->query("cor",1)+victim->query("cps",1 )
                  +victim->query("combat_exp",1)/100000;
        if( !me->query_temp("lockman") 
        && sk>150 && random(3)==0 && me->query_skill_mapped("force") == "bluesea-force"          && !me->is_busy())

        {
               me->set_temp("lockman",1);
               //if (me->query("neili",1) >300) me->add("neili", -50); 
               victim->start_busy(2);
               if( random(mecor) >= random(victimcor))
                {
                   message_vision(CYN"�����Ѷ�ȥ$n"CYN"����־��ʹ$n"CYN"����������������ߵĲ�ϧ���Լ�������ɱȥ����\n"NOR , me , victim );
                   victim->receive_damage("qi",4*sk,me);
                    victim->receive_damage("jing",2*sk,me);
                   if (damage <= 0)
                   COMBAT_D->report_status(victim, 1);
                me->start_busy(1);
                }
                else{
                        message_vision(sprintf(CYN"���������������飬$n"CYN"���ý����ѽ�֯��һ��ɱ�������\n"NOR),me,victim);
                }
         }
         else{
                 me->delete_temp("lockman");
         }
}

//fourok
void four_kill(object me,object victim,object weapon,int damage)
{
 int bell,mk;
 if (!me || !victim) return;
 bell=me->query("bellicosity",1);
 mk=me->query("MKS",1);
 damage= (int)(me->query_skill("love-sword", 1));
 
 if( !me->query_temp("four_kill") )
 {
  if( random(3)==0 && mk < 10000   &&  damage> 200  && me->query_skill_mapped("force") == "bluesea-force"          && !me->is_busy())
   {
me->set_temp("four_kill", 1);
message_vision("\n
                             "HIG"�����氮���森������������"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage,me);
             COMBAT_D->report_status(victim);

message_vision("
                             "HIB"�����氮��֣��������źޡ�"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage,me);
             COMBAT_D->report_status(victim);

message_vision("
                             "HIR"���鰮ûԵ�ݣ�һ�������ˡ�"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage,me);
             COMBAT_D->report_status(victim);
message_vision("
                             "HIC"���鰮��į�ˣ���į��������"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage,me);
             victim->start_busy(random(2)+1);
             COMBAT_D->report_status(victim);
             call_out("five_kill", 1 ,me);
   }
 }
  me->delete_temp("four_kill" );
}
//five ok
int five_kill(object me,object victim,object weapon,int damage)
{
 int sk = me->query_skill("love-sword",1);
 int bell=me->query("bellicosity",1);
 if (!me || !victim) return 0;
 if (sk<=50)sk=50;
 weapon=me->query_temp("weapon");
   message_vision("\n
  "HIY"       $N�����뽣�ѿ�ʼ���˶�����һ�ּ��������������Ķ����������Ƿ���ô��Ȼ\n
  "HIY"                    $N��ͫ����������"+weapon->name()+""HIY"�������Ĵ��˳���\n
  "HIY"             �����˼��Ĳ�λ���˳������̳�ʱ��Ȼ���������˼��ı仯\n
  "HIY"         ���ϸ���û����������һ��������û���κ�����˭��ȥ����һ��������ȥ����\n\n"NOR,me,victim);
 if( random(3)==0  && me->query_skill_mapped("force") == "bluesea-force"          && !me->is_busy())
  {

   message_vision(HIR"              Ѫ��ҫ���ֲ��ã����õ��������ǣ�����һ�ּ��ţ�Ѫ��Ҳ�ܿ������\n"NOR, me);
        victim->add("neili",-2*sk);
        victim->receive_damage("qi",4*sk,me);

        victim->receive_damage("jing",2*sk,me);
        victim->start_busy(2);
//if (me->query("neili",1) >300) me->add("neili", -200);        
  me->start_busy(1);
  }
   else
  {
   message_vision(HIR"              Ѫ��ҫ���ֲ��ã����õ��������ǣ�����һ�ּ��ţ�Ѫ��Ҳ�ܿ������\n"NOR, me);
        victim->add("neili", -2*sk);
        victim->receive_damage("qi",3*sk,me);

        victim->receive_damage("jing",2*sk,me);
        victim->start_busy(1);
//if (me->query("neili",1) >300) me->add("neili", -200); 
  me->start_busy(1);
  }
}

//power_slashok
void power_slash(object me,object victim, object weapon,int damage)
{
 object *enemy,target,env;
 int i,j,bell;
 if (!me || !victim) return;
 bell=me->query("bellicosity",1);
 damage=victim->query("eff_qi",1)/20;
 if (damage>30000) damage=30000;
 env = environment(me);
 enemy=me->query_enemy();
 if (environment(victim)) return;
 if (!env || !enemy) return;
 i=sizeof(enemy);
 for(j=0;j < i;j++){
 victim=enemy[j];
    if( env == environment(victim) && random(3)==0  && me->query_skill_mapped("force") == "bluesea-force"          && !me->is_busy())
    {
     victim->receive_wound("qi", damage,me);
     me->start_busy(1);
     switch(random(4)+1)
    {
     case 1 :
     message_vision(sprintf("\n                               "HBCYN"��������˾���׷�䣮��\n"NOR),me,victim);
     message_vision(sprintf(HIW"��ô�����һ���������Ǵ���$n�����������ȥ������δ�������һ��������޵���һ������ \n"NOR),me,victim);
     break;
     case 2 :
     message_vision(sprintf("\n                               "HBWHT"�������첻�������ˣ���\n"NOR),me,victim);
     message_vision(sprintf(HIW"��ս��⻯����⣬�������£�����������$n�У������˽���������һ������\���� \n"NOR),me,victim);
     break;
     case 3 :
     message_vision(sprintf("\n                               "HBMAG"���������Թſ���ޣ���\n"NOR),me,victim);
     message_vision(sprintf(HIW"һƬ��ɫ����������˰����$n��$n����û��ʹ�࣬û�л��⣬����û��һ����飮��\n"NOR),me,victim);
     break;
     case 4 :
     message_vision(sprintf("\n                               "HBGRN"�����鵽���Թ�ɣ���\n"NOR),me,victim);
     message_vision(sprintf(HIW"��һ��֮����$n�޷����㣬�����������һ��ħ�ǣ�������ע������ôһ�������������\n"NOR),me,victim);
     break;
    }
     COMBAT_D->report_status(victim);
    }
  }
}

//seven ok
void seven(object me,object victim,object weapon,int damage)
{
  int i,mk,da;
  int sk = me->query_skill("love-sword",1);
if (!me || !victim) return;
  mk=me->query("MKS",1);
  weapon=me->query_temp("weapon");
  if(mk < 10000 ) { da = 130; }
  else { da=100; }
 if(  mk<10000 && random(3)==0  && me->query_skill_mapped("force") == "bluesea-force"          && !me->is_busy())
 {
    message_vision(HIW"\n      $N�����յ�"+weapon->name()+""HIW"�·���ɱ�˵�������������������һ�У���һ�в������죮������׼ȷ\n\n"
                 HIW"        $n���еĶ�����������һ��ʹ��ʱ��Ȼ��ȫ��ͣ�٣�Ȼ�����ͽ�����һƬ����\n\n"
                 HIW"                    ����Ľ�Ӱ�������Ѫ����������ת������ת�죬�ɴ����\n\n"
                 HIW"               ��Ȼ�ֻ���һ��ƥ����Ĳʺ죬��ɫ�ʺ죬�߽�����ɶ��ˣ�ǧ����\n\n"NOR,me,victim);
   me->start_busy(1);
    for(i=1;i<=7;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf(HIR"                       --<<��>>��������粻�����������������Ӧ����--\n"NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(YEL"                       --<<��>>�������������ã�������ɣ�����������--\n"NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIY"                       --<<��>>�����������Ъ��������£��������˵--\n"NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIG"                       --<<��>>������������ʣ��������ǿ�ֻ���ζ--\n"NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIB"                       --<<��>>���������Ҳ�˻����ͽ����������ȥ��ʱ--\n"NOR),me,victim);
     break;
     case 6:
message_vision(sprintf(CYN"                       --<<��>>�������������ߣ�������ϣ��������˼�--\n"NOR),me,victim);
     break;
     case 7:
message_vision(sprintf(MAG"                       --<<��>>��������׷��˼��������������˼��\--\n"NOR),me,victim);
     break;
     }
     if( sk > random(30)+100)
     {
message_vision(sprintf(HIC"$n��$N����ɫ����������ȫ�������˺����ۣ�\n"NOR),me,victim);
          victim->receive_wound("qi",da,me);
          
          COMBAT_D->report_status(victim,1);
     }
     else
     {
           message_vision(sprintf(WHT"$n"+WHT"����ֹˮ��������$N"+WHT"�Ľ��ƣ�\n"NOR),me,victim);
     }
   }
 }
}



void dream(object me,object victim,object weapon,int damage)
{
     int mk,damagea,damage1,bell,sena,senb;
     mk = (int)me->query("MKS",1);
     if(mk < 10000)  {damagea = mk/10;  }     //mk<10000  ,����Լ��800-990
     else { damagea = mk/50; }                //mk>10000  ,����Լ��200-600(mk=30000)
                                              //ɱ����Խ��,�����Ż�ǿ
     damage1= 300+random(damagea)+damagea;
if (!me || !victim) return;
     sena = victim->query("max_jing");
     senb = sena/10;
     if (senb> 3000) senb=3000;
     if (damage1 > 30000) damage1 =30000;
     
  if(random(3)==0 && me->query_skill_mapped("force") == "bluesea-force"   && !me->is_busy() )
   {
    if(random(2)==0)
     {
       message_vision(HIW"\n
         $N��������Ҹ����һ�������⣮һ����һ���Ľ��⣮���������ʢ��\n
        "HIW"��ؼ�Ʈҷ��һ���������⣬�����ƻã���������¹�Ͷ������Ĵ� \n
               "HIW"��һ�������졢���١����򵥡���ȥ��ƽ�����森���� \n
               "HIW"Ȼ��ȴ�ǡ���˼���Ρ�һǧ��һʽ�����еľ�����ɱ�У�\n
                           "HIW"��"HIR"�轣����������ն"HIW"�� \n\n"NOR, me);

              //me->add("neili",-random(300));
              victim->receive_damage("qi",damage1,me);
              victim->receive_damage("jing",senb,me);
              COMBAT_D->report_status(victim);
      me->start_busy(1);
      }
      else
      {
        message_vision(HIW"\n
           һ��է�������Ķ���ϸ������������Ѫ�ڶ��ĺ�⣬�Խ���͸�˳���\n
                    "HIW"Ѫ���Ľ�������̫�����°�������$n����Χ\n
              "HIW"$nֻ�����ֿ졢���桢�־������ޡ���������ꡢ����һ��\n
                                  "HIW"��"HIC"���쳾·"HIW"��\n"NOR,me,victim);

        message_vision(HBRED"\n$N�ķ������$n���˷��磬��ʧ�ڷ��쳾֮�У�\n"NOR,me,victim);
        victim->start_busy(random(4)+1);
        victim->receive_damage("qi",1*damagea,me);
      me->start_busy(1);
      }
   }
}


//��˼���ν����İ�����
void heartkill(object me,object victim,object weapon,int damage)
{
  int i;
  int sk = me->query_skill("love-sword",1);
  if (!me || !victim) return;
   if(random(3)==0 && me->query_skill_mapped("force") == "bluesea-force"   && !me->is_busy() )
{
  message_vision(HIC"\n\n\tֻ��$N���������Ž�ʽһ�䣬������������ҫ�۵Ĺ�â�������һƬãã�Ľ�Ļ\n\n"
                 HIW"\t����"BLINK""HIR"   �����쳾����˼����  "NOR""HIW"  ����\n\n"NOR,me,victim);
me->start_busy(1);
    for(i=1;i<=8;i++)
  {
    switch(i)
     {
     case 1:
message_vision(sprintf(HIY"$N���絶���Ȼ���ˣ�ʹ��"HIR"�����쳾"HIW"֮"+NOR+""+RED+"�������ɡ�"+NOR+""+HIY+"������������㹥��$n��\n"NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(HIY"$N�ķ����ң��������ʹ��"HIR"�����쳾"HIW"֮"+NOR+""+GRN+"�������ҡ�"+NOR+""+HIY+"�����������˰����$n��\n"NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIY"$N������㲣���Ȼ��ʧ��ʹ��"HIR"�����쳾"HIW"֮"YEL"����������"+NOR+""+HIY+"�������������ϯ��$n��\n"NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIY"$N�Ĳ����ɣ������ᣬʹ��"HIR"�����쳾"HIW"֮"MAG"��ʧ���֡�"+NOR+""+HIY+"�������������û�$n��\n"NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIY"$N�Ĳ�������ʧ�����ǣ�ʹ��"HIR"�����쳾"HIW"֮"+NOR+""+CYN+"����������"+NOR+""+HIY+"����������Ȱ��Ի�$n��\n"NOR),me,victim);
     break;
     case 6:
message_vision(sprintf(HIY"$N�������ң������御��ʹ��"HIR"�����쳾"HIW"֮"HIB"����������"+NOR+""+HIY+"��������ŭ�ΰ�ӿ��$n��\n"NOR),me,victim);
     break;
     case 7:
message_vision(sprintf(HIY"$N������£��޺����ʹ��"HIR"�����쳾"HIW"֮"HIC"�������ϡ�"+NOR+""+HIY+"�������籯����ǣ��$n��\n"NOR),me,victim);
     break;
     case 8:
message_vision(sprintf(HIY"$N�������ͣ�ƽ�ľ�����ʹ��"HIR"�����쳾"HIW"֮"HIW"�����ĵ���"+NOR+""+HIY+"�����������ΰ�ֱȡ$n��\n"NOR),me,victim);
     break;
     }
     if( random(2)==0)
     {
message_vision(sprintf(MAG"�����$Nȷȷʵʵ������Ҫ����$n������������һ��������˺ۣ�\n"NOR),me,victim);
          victim->receive_wound("qi",200+random(sk),me);

          COMBAT_D->report_status(victim,1);

     }
     else
     {
           message_vision(sprintf(HIB"���$N�Ĺ�����$n���˿�����\n"NOR),me,victim);
     }
   }
}   
}


//��˼���ν����İ���������
void fast(object me,object victim,object weapon,int damage)
{
    int i;

    int sk = me->query_skill("love-sword",1);
if (!me || !victim) return;
    if( (int)me->query("neili") > 300  && random(3)==0 && me->query_skill_mapped("force") == "bluesea-force"   && !me->is_busy())
    {
       message_vision(CYN"\n\n\t$NЦ��΢��������·����һ����Ӱ��һ˲����������һ��������\n\n"
                            HIW"\t����"BLINK""HIR"  ���ΰ��壮��������"NOR""HIW"  ����\n\n"NOR,me,victim);
       for(i=1;i<=3;i++)
       {
         me->start_busy(1);
         switch(i)
         {
            case 1:
            message_vision(HIY"\n����"HIR"��   ��"HIY"����\n"NOR,me,victim);
            message_vision(HIW"�������磬�������Σ���ɫ�ͷף������Ľ��⣬��ͬ�������ŷ绪��\n�ռ�Ϊ�����������"
                                       +"��ʹ⻪�����������һ�����������ڿ������֣�\n��Ѥ��һ������һ��Ļ������\n"NOR,me,victim);
             break;

            case 2:
            message_vision(HIY"\n����"HIR"��   ��"HIY"����\n"NOR,me,victim);
            message_vision(HIW"�����Լ������һ����������������ɱ�⣬�������˷���������ɽ�����Ļ�����\n"+
                                         "����ɢ����������Ŀ�Ĺ�ʣ�Ѫ�Ƶ��ʺ�ɫ���������ң����Ѳ�ɫ���Ρ���\n"NOR,me,victim);
             break;

            case 3:
            message_vision(HIY"\n����"HIR"��   ��"HIY"����\n"NOR,me,victim);
            message_vision(HIW"���׺��𣬴�ظ������������һ������ǿ�⣬�Ѳ���������������������쭺���\n"+
                                        " �·�Ǳ���ص׵�ŭ�������ζ����������죬�������������ƥ����\n"NOR,me,victim);
             break;
           }
           if( random(2)==0)
           {
                  message_vision(MAG"\n$N�Ľ�����������ƻã�$n��������һ����ɼ��ǵ��˺�ȴ����֪��\n"NOR,me,victim);
                  victim->receive_wound("qi",600+random(sk),me);
                  
                  //me->add("neili",-50);
                  if(i != 3)
                  COMBAT_D->report_status(victim,1);
                  else if( damage <=0 )
                  COMBAT_D->report_status(victim,1);
           }
            else
            {
                  message_vision(HIB"$n������$N�Ĺ��ƣ����첻���ı��˿�����\n"NOR,me,victim);
            }
        }
    }
}




//������ֵ�enforce
void disenforce(object me, object victim, object weapon, int damage)
{
        int skillb = (int)me->query_skill("love-sword",1);
        int me_jing = me->query("max_jing")/8;
        int me_qi = me->query("max_qi")/8;
//        int me_jing = me->query("max_jing")/5;
if (!me || !victim) return;
if (me_qi>10000) me_qi=10000;
if (me_jing>10000) me_jing=10000;
//        int victimenf = victim->query("force_factor");
        if( !me->query_temp("disenforce")  && random(3)==0 && me->query_skill_mapped("force") == "bluesea-force"   && !me->is_busy())
        {
          if(skillb >= 100 && random(2)==0)
            {
                message_vision(HIR"\n
             $N�Ľ���������ƽ�����ޱ仯��ȴ��Ȼ�䣬��������һ�ֺ��������\n\n"
HIR"              ���Ʊ����ܿ죬������ʱ��Ȼ������������������Ȼ����ȴ�����ڱ�\n\n"
HIR"                        ��â���֣��������죬������ã����������\n\n"
HIR"                $n������ݹ���·�����Լ�ü�޼䣬�ַ·������޵���翼�\n\n"
NOR"            "HBBLU"���⽣��������$n��־��������$n�Ķ�־����$n����������˱�����\n"NOR, me, victim);
                me->start_busy(1);
                me->set_temp("disenforce",1);
                //victim->set("force_factor", 0);
                victim->receive_wound("jing",me_jing,me);
                victim->receive_wound("qi",me_qi,me);
            }else{ message_vision(NOR"\n"NOR,me,victim);}
        }
        else {me->delete_temp("disenforce");}
}




int valid_learn(object me)
{
        int bell, skill;
        object ob;
        bell=me->query("bellicosity",1 );
        skill =me->query_skill("love-sword", 1);


        if ((int)me->query("max_neili",1) < 500)
                return notify_fail("���������Ϊ̫ǳ���޷��������Ѩ����\n");

        if ((int)me->query_skill("force",1) < 300)
                return notify_fail("��Ļ����ڹ����̫ǳ���޷��������Ѩ����\n");

        if ((int)me->query_skill("sword", 1) < 80)
                return notify_fail("��Ļ����������̫ǳ���޷��������Ѩ����\n");

        if ((int)me->query_skill("sword", 1) < (int)me->query_skill("love-sword", 1))
                return notify_fail("��Ļ�������ˮƽ���ޣ��޷�����������齣��\n");

        if ((int)me->query_skill("bluesea-force", 1) < 300)
                return notify_fail("����Ϻ�����ˮƽ���ޣ��޷�����齣��\n");

        if ((int)me->query_skill("ziwu-daxuefa", 1) < 300)
                return notify_fail("��������Ѩ��ˮƽ���ޣ��޷�����齣��\n");

        if ((int)me->query_skill("ziwu-daxuefa", 1) < (int)me->query_skill("love-sword", 1))
                return notify_fail("��������Ѩ��ˮƽ���ޣ��޷�����������齣��\n");

        if ((int)me->query_skill("bluesea-force", 1) < (int)me->query_skill("love-sword", 1))
                return notify_fail("����Ϻ�����ˮƽ���ޣ��޷�����������齣��\n");


	if( (string)me->query("family/family_name")!="�㵴��")
return notify_fail("�����书Ҫ���㵴�ɵ��������˲���ѧ��\n");

        
         if( me->query("max_neili",1 )<2000 )
         {
                tell_object(me, HIY"���������Ϊ�ƺ��������������齣����\n"NOR);
                return 0;
         }

         if( (me->query("potential",1 )-me->query("learned_points", 1))<50){
                tell_object(me, "���Ǳ�ܲ�����ʮ��, �޷����˽�����\n");
                return 0;
         }

        tell_object(me, HIY"ѧ�˽������Ǳ�ܡ�����������㡣\n");
        me->add("jing", -5);
        me->add("qi", -5);
        me->add("potential", -5);
        return 1;

}


int valid_enable(string usage)
{
        return usage== "sword" || usage=="parry";
}

string perform_action_file(string action)
{
        return __DIR__"love-sword/" + action;
}
