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
	set_name("[31m°×Ñ©Ö®Ø°Ê×[2;37;0m", ({ "general dagger", "dagger" }));
	set_weight(10699);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "°Ñ");
		set("long", @LONG
°×Ñ©Ö®Ø°Ê×[2;37;0mÕâÊÇÒ»°ÑÓÉÊ®·Ö¼áÓ²µÄ[33mÉúÌú[2;37;0mÖÆ³É£¬ÖØ¶şÊ®Ò»½ïÈıÁ½¾ÅÇ®µÄ[31m°×Ñ©Ö®Ø°Ê×[2;37;0m¡£
×ÛºÏÆÀ¼Û[31mÍêÃÀ¾«ÖÂ[2;37;0m ¿´ÆğÀ´Ê®·Ö·æÀû£¬¾ßÓĞ[35m¼«Æä¿ÉÅÂ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[34mÏ¸Ëé[2;37;0m [1;35m·ç[2;37;0m:[1;36mÍêÃÀ[2;37;0m 
[1;34mµç[2;37;0m:[32m´Ö²Ú[2;37;0m [37mÌì[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[32m´Ö²Ú[2;37;0m ÇÉÖÆ:[34mÏ¸Ëé[2;37;0m 
ÉÁµç:[36m²»´í[2;37;0m 


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
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",0);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 15);
    set("weapon_prop/armor", 21);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 0);
    set("weapon_prop/jing", 0);
    set("weapon_prop/jingli", 0);
    set("weapon_prop/damage", 0);

    set("wtypeA",2);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",7);
    set("wtypeG",0);
    set("wtypeH",3);
    set("wtypeI",8);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 3);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_dagger(436);
	setup();
}



#include "/obj/ritem/weaponzy.h";