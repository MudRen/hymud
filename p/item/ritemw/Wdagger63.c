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
	set_name("[35m¹ÖÖ®Ø°Ê×[2;37;0m", ({ "bad dagger", "dagger" }));
	set_weight(4052);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
¹ÖÖ®Ø°Ê×[2;37;0mÕâÊÇÒ»°ÑÓÉ»¹Ëã¼áÓ²µÄ[32mÇàÍ­[2;37;0mÖÆ³É£¬ÖØ°Ë½ïÒ»Á½ÁãÇ®µÄ[35m¹ÖÖ®Ø°Ê×[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´»¹Ëã·æÀû£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[36m²»´í[2;37;0m [31m»ğ[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[36m²»´í[2;37;0m ÌìÁé:[33mÒ»°ã[2;37;0m ¾ø´ú:[33mÒ»°ã[2;37;0m °×Ê¯:[32m¼«²î[2;37;0m ²»ÀÏ:[33mÒ»°ã[2;37;0m 

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
		set("weapon_prop/intelligence",6);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",6);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 5);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 7);
    set("weapon_prop/jingli", 7);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",1);
    set("wtypeD",6);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "throwing",
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
	
	init_dagger(276);
	setup();
}



#include "/obj/ritem/weaponzy.h";