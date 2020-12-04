#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[1;36mÑÅµäÄÈÖ®ÎÇ[2;37;0m", ({ "shentong neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "´®");
		set("long", @LONG
[1;31mÌì±øÉñÍ¨£¬×ßÊÆÒªÆ½ÉÆ£¬ÆøÒªËæĞĞ£¬Á½ÑÛ¹Ë¼â£¬Æø³ÁÁ½×ãÎÈ£¬
Éí·¨Ğè×ÔÈ»£¬ÉíĞĞÈç·ÉÑà£¬ÉíÂäÈçÍ£·ç£¬ÊÕÈç»¨Ğõ£¬´ÌÈç¸Ö¶¤£¡
[2;37;0mÕâÊÇÒ»´®ÓÉÎŞ±È¼áÓ²µÄ[37mĞşÌú[2;37;0m¼ÓÉÏ[1;37m±ù²ÏË¿[2;37;0mÖÆ³É£¬ÖØËÄ½ïÁùÁ½¶şÇ®µÄ[1;31mÉñÍ¨Ö®ÏîÁ´[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[34m²»´í[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[1;35m¾øÊÀ[2;37;0m [33mÍÁ[2;37;0m:[1;34m¾ÙÊÀ[2;37;0m [1;35m·ç[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
[1;37mÀ×[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;31m»ÙÌì[2;37;0m ÌìĞş:[34mÏ¸Ëé[2;37;0m ÇÉÖÆ:[31m¾«ÖÂ[2;37;0m 
°×Ê¯:[1;36mÍêÃÀ[2;37;0m ³¤Éú:[32m´Ö²Ú[2;37;0m ²»ÀÏ:[35m±ê×¼[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mµØÍ¼Ò»ºÅ[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32m´¸·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "µØÍ¼Ò»ºÅ");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",27);
    set("armor_prop/dodge", 73);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 48);


    set("armor_prop/armor", 282);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 32);
    set("armor_prop/jing", 54);
    set("armor_prop/jingli", 54);
    set("armor_prop/damage", 156);

    set("wtypeA",0);
    set("wtypeB",11);
    set("wtypeC",0);
    set("wtypeD",5);
    set("wtypeE",8);
    set("wtypeF",9);
    set("wtypeG",14);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",5);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";