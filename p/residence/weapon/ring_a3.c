#include <ansi.h> 
#include <armor.h>

inherit BOOTS;

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

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;33mÁè²¨½ğÁ«[2;37;0m", ({ "yuchang boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ë«");
		set("long", @LONG
[31mÓã³¦ÇáÇÉÎŞ±È£¬ÄÜ¿ªÌì±ÙµØ£¬µ´Ñı³ıÄ§£¡
[2;37;0mÕâÊÇÒ»Ë«ÓÉÎŞ±È¼áÓ²µÄ[1;36mÍòÄêº®±ùÌú[2;37;0m¼ÓÉÏ[1;33mÁú¼ë²ÏË¿[2;37;0mÖÆ³É£¬ÖØÎå½ï°ËÁ½°ËÇ®µÄ[31mÓã³¦Ö®Ñ¥[2;37;0m¡£
×ÛºÏÆÀ¼Û[35m»ÙÌìÃğµØ[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[32mË®×¼ÒÔÉÏ[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[37mÌì[2;37;0m:[1;35m¾øÊÀ[2;37;0m [1;31mÄ§[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [32mË®[2;37;0m:[1;32mÄ§Íõ[2;37;0m [1;35m·ç[2;37;0m:[1;31m»ÙÌì[2;37;0m 
[1;37mÀ×[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÃğÊÀ[2;37;0m ÇÉÖÆ:[1;36mÍêÃÀ[2;37;0m 
×ÏÊ¯:[35m±ê×¼[2;37;0m ÉÁµç:[33mºÜ¸ß[2;37;0m 
ÖÜÌì:[1;36mÍêÃÀ[2;37;0m ³¤Éú:[31m¾«ÖÂ[2;37;0m ²»ÀÏ:[1;36mÍêÃÀ[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mïLâ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m¹÷·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ring");
		set("ownername", "ïLâ");
		set("value", 36000);
		set("armor_prop/intelligence",72);
		set("armor_prop/strength",72);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",72);
		set("armor_prop/constitution",72);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 54);
    set("armor_prop/attack", 72);


    set("armor_prop/armor", 383);
    set("armor_prop/defense", 72);
    
    set("armor_prop/neili", 76);
    set("armor_prop/qi", 61);
    set("armor_prop/jing", 77);
    set("armor_prop/jingli", 77);
    set("armor_prop/damage", 123);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",9);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",15);
    set("wtypeG",9);
    set("wtypeH",0);
    set("wtypeI",11);
    set("wtypeJ",0);
    set("wtypeK",9);
    set("wtypeL",9);
    
    
                set("skill", ([
                        "name": "club",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 480,              
                ]) );		


		set("material", "default");
    set("sharpness", 21);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";