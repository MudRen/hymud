//Cracked by Kafei
// by oyxb
// by acep

#include <ansi.h>
string* xuedao = ({
        "¾Þ¹ÇÑ¨",
        "µØ²ÖÑ¨",
        "¼ç¾®Ñ¨",
        "¼Õ³µÑ¨",
        "³ÐÆüÑ¨",
        "·ç³ØÑ¨",
        "ÕÂÃÅÑ¨",
        "·ç¸®Ñ¨",
        "¾«´ÙÑ¨",
        "ÌÕµÀÑ¨",
        "Ç¿¼äÑ¨",
        "ÉÙº£Ñ¨",
        "¶¿±ÇÑ¨",
        "ÉñÃÅÑ¨",
        "»ª¸ÇÑ¨",
        "´ó×µÑ¨",
        "·ïÎ²Ñ¨",
        "ÖÁÑôÑ¨",
        "ÀÍ¹¬Ñ¨",
        "°Ù»áÑ¨",
        "ÁéÌ¨Ñ¨",
        "Ì«ÑôÑ¨",
        "ëþÖÐÑ¨",
        "ÃüÃÅÑ¨",
        "ð¯Î²Ñ¨",
        "ÈýÒõ½»",
        "ÌìÖùÑ¨"
});


int update_condition(object me, int duration)
{
	object ob;
	int damage;
	damage= (int)me->query("qi",1)/20;
   if (damage>5000) damage=5000;
   if( duration < 1 ) return 0;
	if (!living(me)) {
		message("vision", me->name() + "ÃÆºßÁËÒ»Éù¡£\n", environment(me), me);
	}
		tell_object(me,HIR"Äã¸Ðµ½"+xuedao[random(sizeof(xuedao))]+"Ò»ÕóËáÂé£¬ÑªÆø²»³©£¬¶ÙÊ±¶¯µ¯²»µÃ£¡\n"NOR);
  if( !me->is_busy() )
{ 
		me->start_busy(5);
}
                me->receive_damage("qi", damage);
                me->receive_wound("qi", damage);
      me->apply_condition("yyz_damage", duration - 1);
      if( duration < 1 ) return 0;
	return 1;
}
