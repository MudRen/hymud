// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit DAGGER;

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
	set_name("[1;35m´óÖ®Ø°Ê×[2;37;0m", ({ "bad dagger", "dagger" }));
	set_weight(14523);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
´óÖ®Ø°Ê×[2;37;0mÕâÊÇÒ»°ÑÓÉ·Ç³£¼áÓ²µÄ[32mÇàÍ­[2;37;0mÖÆ³É£¬ÖØ¶şÊ®¾Å½ïÁãÁ½ËÄÇ®µÄ[1;35m´óÖ®Ø°Ê×[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´·Ç³£·æÀû£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[33mÍÁ[2;37;0m:[32m´Ö²Ú[2;37;0m [1;35m·ç[2;37;0m:[36m²»´í[2;37;0m 
[1;31mÄ§[2;37;0m:[35m±ê×¼[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[36m²»´í[2;37;0m ÌìÓî:[32m¼«²î[2;37;0m ¸£Ô´:[33mÒ»°ã[2;37;0m 
ÖÜÌì:[33mÒ»°ã[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",5);
		set("weapon_prop/karey",6);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 8);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",3);
    set("wtypeF",1);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",5);
    

                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 1);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_dagger(234);
	setup();
}



#include "/obj/ritem/weaponzy.h";