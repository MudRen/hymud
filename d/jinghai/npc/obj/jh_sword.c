// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit SWORD;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[31m¾¸º£Ö®½£[2;37;0m", ({ "jinghai sword", "sword" }));
	set_weight(11146);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", @LONG
[31m¾¸º£Ö®½£ÇáÇÉÎŞ±È£¬ÄÜ¿ªÌì±ÙµØ£¬µ´Ñı³ıÄ§£¡

LONG
);
    set("no_pawn",1);
		set("value", 36000);
		set("weapon_prop/intelligence",1);
		set("weapon_prop/strength",1);
		set("weapon_prop/karey",1);
		set("weapon_prop/percao",1);
		set("weapon_prop/dexerity",1);
		set("weapon_prop/constitution",1);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 1);
    set("weapon_prop/qi", 1);
    set("weapon_prop/jing", 1);
    set("weapon_prop/jingli", 1);


    set("wtypeA",0);
    set("wtypeB",1);
    set("wtypeC",1);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",1);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",1);
    set("wtypeL",1);
    
    set("treasure",1);   
		

		set("material", "default");
    set("sharpness", 5);

		set("wield_msg", HIB"$N½«$nÎÕÔÚÊÖÖĞ¡£Ó¡ÏÖ³ö´óº£µÄ¹âÃ¢£¡\n"NOR);
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_sword(555);
	setup();
}



mixed hit_ob(object me, object victim, int damage_bonus)
{
        int n,sharpness,damage;
object weapon;
sharpness=query("sharpness");
if (!sharpness) sharpness=0;
if (random(sharpness) > 2 && random(6)==0)
{

                victim->receive_damage("qi", sharpness * 10);
                victim->receive_wound("qi", sharpness * 10);
                return RED "$N" HIY "ÊÖÖĞ"+query("name")+RED"Ò»²ü£¬ÑúÆğ²ã²ã½ğ¹â£¬¶ÙÊ±½«$n"
                       RED "»®ÉË£¡ÏÊÑªË³×Å$nÉíÉÏÖ±ÍùÏÂÁ÷£¡\n" NOR;
}
if (random(3)==0)
{
        switch (random(12))
        {
        case 0:
                if (query("wtypeA") >0)
{
                if (! victim->is_busy())
                victim->start_busy(query("wtypeA") + 2);
                return query("name")+HIY"½ğ¹âÒ»ÉÁ£¬ÉÁ¹ıÁË$nµÄË«ÑÛ£¡"
                       "$n" HIY "Ö»¾õÍ·ÔÎÄ¿Ñ££¬¼¸Óû»èØÊ£¡\n" NOR;
}
        case 1:
                if (query("wtypeB") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeB") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeB") * 50);
                return query("name")+ CYN "ÂÌ¹âÒ»ÉÁ£¬$N" CYN "Éí±ßÊ÷Ä¾µÄÉúÃü»îÁ¦"
                       "Ê¹$N" CYN "µÄÉíÌåµÃµ½ÁË»Ö¸´£¡\n" NOR;
}
        case 2:
                if (query("wtypeC") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeC") * 30);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeC") * 30);
                victim->start_busy(3);
                return query("name")+ GRN "Ë®¹âÒ»ÉÁ£¬$N" GRN "µÄÆøÉ«ºÃÒ»Ğ©"
                       "$n¸Ğµ½Ò»Õó±ùÁ¹£¬²»ÄÜ¶¯µ¯ÁË£¡\n" NOR;
}
        case 3:
                 if (query("wtypeD") >0)
{

                victim->receive_damage("qi", query("wtypeD") * 50);
                victim->receive_wound("qi", query("wtypeD") * 50);
                return query("name")+ RED "»ğ¹âÒ»ÉÁ£¬$n" RED "´ó½ĞÒ»Éù ²»ºÃ"
                       "$n»ëÉÏÉÕ×ÅÁË£¡\n" NOR;
}
        case 4:
                if (query("wtypeE") >0)
{
if( (int)me->query("neili") < (int)me->query("max_neili")*2  )
                me->add("neili", query("wtypeE") * 60);
                return query("name")+ GRN "ÍÁ¹âÒ»ÉÁ£¬$N" GRN "µ¤ÌïÒ»Å¯£¬µÄÔªÆø»ÖµÃÁË²»ÉÙ¡£\n" NOR;                                           
 }
        case 5:
                if (query("wtypeF") >0)
{
if (victim->query("apply/dodge",1) >= -200)
		victim->add_temp("apply/dodge", -(8 * query("wtypeF")));
if (victim->query("apply/defense",1) >= -200)
		victim->add_temp("apply/defense", -(8 * query("wtypeF")));
                return query("name")+ HIM "ÕĞÀ´Ò»Õó·ç£¬·ÉÎèÔÚ¿ÕÖĞµÄÎŞĞÎÖ®ÀûÈĞ°üÎ§×Å$n£¬$n" HIM "Ö»¾õ´ç²½ÄÑĞĞ£¡\n" NOR;
}
        case 6:
                if (query("wtypeG") >0)
{

			damage = 30 * query("wtypeG") ;
if ((int)victim->query("neili")+10 > (damage*30))
		victim->add("neili", -damage*30);
if ((int)victim->query("jing")+10 > damage)
		victim->receive_wound("jing", damage);
                return query("name")+ HIW "ÕĞÀ´Ò»µÀÀ×£¬Ò»ÉÁ¶ø¹ı»÷ÖĞÁË$n£¬$n" HIW "Ö»¾õµÃÈ«ÉíÓÖÍ´ÓÖÂé£¡\n" NOR;
}
        case 7:
                if (query("wtypeH") >0)
{
if (victim->query("apply/attack",1) >= -200)
		victim->add_temp("apply/attack", -(8 * query("wtypeH")));
if (victim->query("apply/parry",1) >= -200)
		victim->add_temp("apply/parry", -(8 * query("wtypeH")));
                return query("name")+ HIB "ÕĞÀ´Ò»Õóµç£¬µç¹âÒ»ÉÁ»÷ÖĞÁË$n£¬$n" HIB "Ö»¾õ»ìÉíÂé±Ô£¡\n" NOR;

}
        case 8:
                if (query("wtypeI") >0)
{
if( (int)me->query("eff_qi") < (int)me->query("max_qi")  )
                me->add("eff_qi", query("wtypeI") * 20);
if( (int)me->query("qi") < (int)me->query("max_qi")  )
                me->add("qi", query("wtypeI") * 20);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")  )
                me->add("eff_jing", query("wtypeI") * 20);
if( (int)me->query("jing") < (int)me->query("max_jing")  )
                me->add("jing", query("wtypeI") * 20);
if( (int)me->query("neili") < (int)me->query("max_neili")  )
                me->add("neili", query("wtypeI") * 30);
                return query("name")+ WHT "ÉÁ¹ıÌì¿ÕµÄ¹âÔó£¬$N" WHT "È«ÉíÆøÉ«·¢ÉíÁË±ä»¯\n" NOR;

}
        case 9:
                if (query("wtypeJ") >0)
{
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
victim->apply_condition(du[random(sizeof(du))], query("wtypeJ")*3);
                return query("name")+ YEL "ÉÁ¹ı´óµØµÄ¹âÔó£¬»ÆÉ«µÄÑÌÎí´ÓµØÉÏ³öÏÖ°üÎ§ÁË$n£¬$n" YEL "Ö»¾õÆøÑªÒ»ÕóÄæÁ÷£¡\n" NOR;
}
        case 10:
                if (query("wtypeK") >0)
{

		if (objectp(weapon = victim->query_temp("weapon"))) {
			if (random(query("weapon_prop/damage")) > weapon->query("weapon_prop/damage") / 2
			&& random(me->query("str")) > victim->query("str") / 2
			&& random(6)==0) {
				victim->start_busy(random(query("wtypeK")) + 3);
					message_vision(HIW"Ö»Ìı¼û¡¸ßÑ¡¹µØÒ»ÉùÇáÏì£¬$NÊÖÖĞµÄ" + weapon->query("name") + HIW"ÒÑ¾­±»" + query("name") + HIW"Ï÷ÎªÁ½½Ø£¡\n"NOR, victim);
					weapon->unequip();
					weapon->move(environment(victim));
					weapon->set("name", "¶ÏµôµÄ" + weapon->query("name"));
					weapon->set("value", 0);
					weapon->set("weapon_prop", 0);
					victim->reset_action();
}
}

if( (int)victim->query("neili") >0  )
                victim->add("neili", -query("wtypeK") * 60);
if( (int)me->query("neili") < (int)me->query("max_neili")*3  )
                me->add("neili", query("wtypeK") * 60);

                return query("name")+ HIC "ÉÁ¹ıÈËÀàµÄÍõÕßÖ®Æø¡£$n" HIC "Ë«ÑÛÒ»»¨£¬¾õºÍÈ«ÉíµÄÄÚÁ¦¸øÍõÕßÖ®ÆøÎü×ßÁË£¡\n" NOR;
}
        case 11:
                if (query("wtypeL") >0)
{

if( (int)victim->query("eff_qi") >0  )
                victim->add("eff_qi", -query("wtypeL") * 50);
if( (int)me->query("eff_qi") < (int)me->query("max_qi")*3  )
                me->add("eff_qi", query("wtypeL") * 50);
if( (int)me->query("qi") < (int)me->query("max_qi")*3  )
                me->add("qi", query("wtypeL") * 50);


if( (int)victim->query("eff_jing") >0  )
                victim->add("eff_jing", -query("wtypeL") * 30);
if( (int)me->query("eff_jing") < (int)me->query("max_jing")*3  )
                me->add("eff_jing", query("wtypeL") * 30);
if( (int)me->query("jing") < (int)me->query("max_jing")*3  )
                me->add("jing", query("wtypeL") * 30);                
return query("name")+ HIR "Ä§¹âÒ»ÏÖ£¬$n" HIR "Ö»¾õ¹í¿ŞÀÇº¿Éù²»¾øÓÚ¶ú£¬Èı»êÁùÆÇ¶¼¸øÎüÁË³öÈ¥£¡£¡\n" NOR;                                                                                                                                        
}
        }
}        
        
        return damage_bonus;
}
