// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit THROWING;

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
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

void create()
{
	set_name("[1;32m¾ÅÓÄÖ®°µÆ÷[2;37;0m¡ï", ({ "jiuyou throwing", "throwing" }));
	set_weight(722);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "Ö§");
		set("long", @LONG
[1;32m¾ÅÓÄÖ®°µÆ÷[2;37;0mÕâÊÇÒ»Ö§ÓÉÎŞ±È¼áÓ²µÄ[1;32mÂÌÊ¯[2;37;0mÖÆ³É£¬ÖØÒ»½ïËÄÁ½ËÄÇ®µÄ[1;32m¾ÅÓÄÖ®°µÆ÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[37m¾øÊÀÎŞË«[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;36mÕ¶Ñı·üÄ§[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;31mÎŞË«[2;37;0m [1;31mÄ§[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÓî:[36m²»´í[2;37;0m ÌåÁé:[36m²»´í[2;37;0m ³¤Éú:[36m²»´í[2;37;0m ²»ÀÏ:[32m´Ö²Ú[2;37;0m ÍşÁ¦:[32m´Ö²Ú[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 16000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",16);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 17);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 16);
    set("weapon_prop/jing", 35);
    set("weapon_prop/jingli", 35);
    set("weapon_prop/damage", 32);

    set("wtypeA",0);
    set("wtypeB",12);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",6);
    

                set("skill", ([
                        "name": "dodge",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 18);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	set_amount(1);
	init_throwing(595);
	setup();
}



#include "/obj/ritem/weaponzy.h";