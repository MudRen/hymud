//by dewbaby@sk_sjsh
//九剑·情绝

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
	string msg;
	int extra;
	int i;
	object weapon,victim;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;
        int ap, dp, fp, pp,count;

        string str;
        int j;
int skill, neili_wound, qi_wound;

        weapon = me->query_temp("weapon");

      if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对！\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail("只能在战斗中对对手使用。\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("这个绝技只能空手使用。\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("love-sword", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("bluesea-force", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
          //      return notify_fail("用这门剑法，如何使用本门绝学!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("你必须空手才能使用本门绝学!\n");

        msg = HBWHT "$N贯通雁荡武学，使出了雁荡的绝学之精髓！\n" NOR;
message_vision(msg, me, target);               
victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}


     
        lvl = me->query_skill("love-sword", 1);
         message_vision("
"HIR"$N剑意纵横，分影倏忽，仿佛斩出了岁月惊心\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);
message_vision("
"HIY"--两情若在长久时．又岂在朝朝暮暮--"NOR"
"HIR"$N平凡一剑，陷溺迷惘，仿佛带出了岁月痴情\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);

message_vision("
"HIY"--天涯地角有穷时．只有相思无尽处--"NOR"
"HIR"$N剑如彩云，灿烂夺目，仿佛舞出了岁月华彩\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);

message_vision("
"HIY"--衣带渐宽终不悔．为伊消得人憔悴--"NOR"
"HIR"$N剑光闪烁，左右飘荡，仿佛动出了岁月无情\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);

message_vision("
"HIY"--无情不似多情苦．一寸还成千万缕\--"NOR"
"HIR"$N剑意孤独，灰飞烟灭，仿佛幻出了岁月无奈\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);

message_vision("
"HIY"--此情可待成追忆．只是当时已惘然--"NOR"
"HIR"$N剑光一道，夺人心魄，仿佛照出了岁月光华\n"NOR,me,victim);
victim->receive_wound("qi",random(lvl)+1,me);

             COMBAT_D->report_status(victim);
         



message_vision("\n
"HIY"$N的人与剑已开始有了动作，一种极缓慢，极优美的动作，就像是风那么自然
"HIY"$N的瞳孔在收缩，"+weapon->name()+""HIY"已慢慢的刺了出来
"HIY"从最不可思议的部位刺了出来，刺出时忽然又有了最不可思议的变化
"HIY"世上根本没有人能破这一剑，绝对没有任何人能谁想去破这一剑，就是去送死\n"NOR,me,victim);
if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
  {
   message_vision(HIR"血花耀眼又灿烂，灿烂的婉如流星，流星一现即逝，血花也很快的洒下\n"NOR, me);
                damage = me->query_skill("love-sword",1);
                target->receive_damage("qi", damage*4,me);
                target->receive_wound("qi", damage*4,me);
  }
   else
  {
   message_vision(HIR"血花耀眼又灿烂，灿烂的婉如流星，流星一现即逝，血花也很快的洒下\n"NOR, me);
  }


  message_vision(HIW"$N手中握的"+weapon->name()+""HIW"仿佛是杀人的利器，精华，致命的一招，这一招不但诡异．毒辣．准确"
                 HIW"$n所有的动作，竟在这一剑使出时忽然间全部停顿，然后苍穹间就溅出了一片花雨"
                 HIW"满天的剑影，满天的血花，剑花又转，由慢转快，由纯变混"
                 HIW"忽然又化作一道匹练般的彩红，七色彩红，七剑，多采多姿，千变万化\n"NOR,me,victim);
if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

     {
message_vision(sprintf(HIC"$n被$N的七色剑意所困，全身上下伤痕累累！\n"NOR),me,victim);
                damage = me->query_skill("bluesea-force",1);
                target->receive_damage("qi", damage*4,me);
                target->receive_wound("qi", damage*4,me);
     }
     else
     {
           message_vision(sprintf(WHT"$n"+WHT"心如止水，看清了$N"+WHT"的剑势！\n"NOR),me,victim);
     }
           
       message_vision(HIW"$N右手自左腋出手一剑，剑光．一闪．一闪的剑光．剑上蓝焰大盛！
"HIW"天地间飘曳起一道幽幽蓝光，似真似幻，如沉静的月光投入深邃的大海 
"HIW"这一剑，极快、极速、极简单、看去极平凡无奇．．． 
"HIW"然而却是“相思碎梦”一千零一式中所有的精华和杀招！
"HIW"‘"HIR"舞剑．卷尘．风行斩"HIW"’ \n"NOR, me);
if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

     {
 message_vision(HIW"一种乍看令人心动，细看足以让人心血贲动的红光，自剑身透了出来
"HIW"血红般的剑气有如太阳西下般撩绕在$n的周围
"HIW"$n只觉得又快、又奇、又绝、惊艳、潇洒、惆怅、不可一世
"HIW"‘"HIC"烽火红尘路"HIW"’\n"NOR,me,victim);
        message_vision(HBRED"$N的烽火剑气让$n乱了方寸，迷失在烽火红尘之中！\n"NOR,me,victim);
                damage = me->query_skill("love-sword",1);
                target->receive_damage("qi", damage*4,me);
                target->receive_wound("qi", damage*4,me);
     }
     else
     {
           message_vision(sprintf(WHT"$n"+WHT"心如止水，看清了$N"+WHT"的剑势！\n"NOR),me,victim);
     }



       message_vision(CYN"$N笑意微泛，眼里仿佛出现一道阴影，一瞬而过，剑光一闪。。。"
                            HIW"\t～～"BLINK""HIR"  碎梦奥义．回天梦舞"NOR""HIW"  ～～\n"NOR,me,victim);
          message_vision(HIY"＝＝"HIR"醉   梦"HIY"＝＝\n"NOR,me,victim);
            message_vision(HIW"剑荡剑风，剑美如梦，彩色缤纷，绝美的剑光，如同惊艳遇着风华，\n空间为奇彩所充满，"
                                       +"五彩光华，如痴如醉，似一连串的迷梦在空中闪现，\n迷绚于一连串梦一般的幻像里。。\n"NOR,me,victim);
          message_vision(HIY"＝＝"HIR"惊   梦"HIY"＝＝\n"NOR,me,victim);
            message_vision(HIW"剑光绰约，腾起一阵凌厉而且艳丽的杀意，剑气如浪分涛裂似排山倒海的击出，\n"+
                                         "剑光散开，发出夺目的光彩，血似的鲜红色，凄艳亮烈，惊醒彩色的梦。。\n"NOR,me,victim);
          message_vision(HIY"＝＝"HIR"碎   梦"HIY"＝＝\n"NOR,me,victim);
            message_vision(HIW"天雷忽起，大地浮沉，剑光摒出一道道的强光，裂苍天而出，震苍生而鸣，狂飙忽起，\n"+
                                         "仿佛潜伏地底的怒龙，裂梦而起，上七重天，升九万里，势所无匹。。\n"NOR,me,victim);

if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

     {

 message_vision(MAG"$N的剑法舞的如梦似幻，$n身上着了一道深可见骨的伤痕却不自知！\n"NOR,me,victim);
                damage = me->query_skill("love-sword",1);
                target->receive_damage("qi", damage*4,me);
                target->receive_wound("qi", damage*4,me);
     }
     else
     {
                  message_vision(HIB"$n看清了$N的攻势，不徐不疾的避了开来！\n"NOR,me,victim);
     }

        //me->add_temp("apply/sword", -lvl/3);
        me->start_busy(4);
        return 1;
}